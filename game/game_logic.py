import json
from PyQt5.QtWidgets import QMessageBox, QFileDialog

class GameLogic:
    def __init__(self, board):
        self.board = board
        self.current_player = "X"
        self.next_board = None

    def make_move(self, row, col, sub_row, sub_col):
        button = self.board.board[row][col][sub_row][sub_col]
        if button.text() == "" and (self.next_board is None or self.next_board == (row, col)):
            button.setText(self.current_player)
            if self.current_player == "X":
                button.setStyleSheet(
                    f"font-size: 24px; color: {self.board.colour_x}; background-color: {self.board.colour_main};"
                )
            else:
                button.setStyleSheet(
                    f"font-size: 24px; color: {self.board.colour_o}; background-color: {self.board.colour_main};"
                )

            if self.check_winner(row, col, sub_row, sub_col):
                self.board.update_sub_board(row, col, self.current_player)
                if self.check_winner_main_board():
                    QMessageBox.information(self.board.main_window, "Game Over",
                                            f"{self.current_player} wins the game!")
                    self.board.reset_board()
                    return
            elif self.check_draw(row, col):
                QMessageBox.information(self.board.main_window, "Game Over", "Game over with draw!")
                self.board.reset_board()
                return

            self.current_player = "O" if self.current_player == "X" else "X"
            self.next_board = (sub_row, sub_col) if self.board.sub_board_status[sub_row][sub_col] is None else None
            self.board.main_window.update_current_player_label()
            self.board.highlight_available_moves()

    def check_winner(self, row, col, sub_row, sub_col):
        sub_board = self.board.board[row][col]
        if all(sub_board[sub_row][i].text() == self.current_player for i in range(self.board.sub_board_size)) or \
                all(sub_board[i][sub_col].text() == self.current_player for i in range(self.board.sub_board_size)) or \
                all(sub_board[i][i].text() == self.current_player for i in range(self.board.sub_board_size)) or \
                all(sub_board[i][self.board.sub_board_size - 1 - i].text() == self.current_player for i in range(self.board.sub_board_size)):
            return True
        return False

    def check_draw(self, row, col):
        sub_board = self.board.board[row][col]
        for sub_row in range(self.board.sub_board_size):
            for sub_col in range(self.board.sub_board_size):
                if sub_board[sub_row][sub_col].text() == "":
                    return False
        return True

    def check_winner_main_board(self):
        if all(self.board.sub_board_status[i][i] == self.current_player for i in range(self.board.board_size)) or \
                all(self.board.sub_board_status[i][self.board.board_size - 1 - i] == self.current_player for i in range(self.board.board_size)) or \
                any(all(self.board.sub_board_status[row][i] == self.current_player for i in range(self.board.board_size)) for row in range(self.board.board_size)) or \
                any(all(self.board.sub_board_status[i][col] == self.current_player for i in range(self.board.board_size)) for col in range(self.board.board_size)):
            return True
        return False

    def save_game(self):
        state = {
            "current_player": self.current_player,
            "next_board": self.next_board,
            "board": [[[button.text() for button in row] for row in col] for col in self.board.board],
            "sub_board_status": self.board.sub_board_status,
        }
        file_name, _ = QFileDialog.getSaveFileName(self.board.main_window, "Save Game", "", "JSON Files (*.json)")
        if file_name:
            with open(file_name, "w") as file:
                json.dump(state, file)

    def load_game(self):
        file_name, _ = QFileDialog.getOpenFileName(self.board.main_window, "Load Game", "", "JSON Files (*.json)")
        if file_name:
            with open(file_name, "r") as file:
                state = json.load(file)

            self.current_player = state["current_player"]
            self.next_board = tuple(state["next_board"]) if state["next_board"] else None

            for row in range(self.board.board_size):
                for col in range(self.board.board_size):
                    for sub_row in range(self.board.sub_board_size):
                        for sub_col in range(self.board.sub_board_size):
                            button = self.board.board[row][col][sub_row][sub_col]
                            button.setText(state["board"][row][col][sub_row][sub_col])
                            if button.text() == "X":
                                button.setStyleSheet(
                                    f"font-size: 24px; color: {self.board.colour_x}; background-color: {self.board.colour_main};"
                                )
                            elif button.text() == "O":
                                button.setStyleSheet(
                                    f"font-size: 24px; color: {self.board.colour_o}; background-color: {self.board.colour_main};"
                                )
                            else:
                                button.setStyleSheet(f"font-size: 24px; background-color: {self.board.colour_main};")

            self.board.sub_board_status = state["sub_board_status"]
            for row in range(self.board.board_size):
                for col in range(self.board.board_size):
                    if self.board.sub_board_status[row][col]:
                        self.board.update_sub_board(row, col, self.board.sub_board_status[row][col])

            self.board.main_window.update_current_player_label()
            self.board.highlight_available_moves()
