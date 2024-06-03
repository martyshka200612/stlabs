from PyQt5.QtWidgets import QWidget, QGridLayout, QPushButton, QLabel, QColorDialog
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QFont

class Board:
    def __init__(self, main_window):
        self.main_window = main_window
        self.board_size = 3
        self.sub_board_size = 3
        self.board = [[None for _ in range(self.board_size)] for _ in range(self.board_size)]
        self.sub_board_status = [[None for _ in range(self.board_size)] for _ in range(self.board_size)]
        self.sub_board_labels = [[None for _ in range(self.board_size)] for _ in range(self.board_size)]

        self.colour_x = "#000000"
        self.colour_o = "#000000"
        self.colour_main = "#FF1493"
        self.highlight_colour = "#FFB6C1"
        self.background_colour = "#FFFFFF"

        self.grid_layout = QGridLayout()
        self.init_board()

    def init_board(self):
        for row in range(self.board_size):
            for col in range(self.board_size):
                sub_board = QWidget()
                sub_board_layout = QGridLayout()
                sub_board.setLayout(sub_board_layout)
                self.board[row][col] = [[None for _ in range(self.sub_board_size)] for _ in range(self.sub_board_size)]

                for sub_row in range(self.sub_board_size):
                    for sub_col in range(self.sub_board_size):
                        button = QPushButton("")
                        button.setFixedSize(80, 80)
                        button.setStyleSheet(
                            f"font-size: 24px; border: 1px solid black; background-color: {self.colour_main};"
                        )
                        button.clicked.connect(
                            lambda checked, r=row, c=col, sr=sub_row, sc=sub_col: self.main_window.game_logic.make_move(r, c, sr, sc))
                        sub_board_layout.addWidget(button, sub_row, sub_col)
                        self.board[row][col][sub_row][sub_col] = button

                sub_board_label = QLabel("", sub_board)
                sub_board_label.setAlignment(Qt.AlignCenter)
                sub_board_label.setFont(QFont("Arial", 150, QFont.Bold))
                sub_board_label.setStyleSheet("color: rgba(0, 0, 0, 0);")  # Initially invisible
                sub_board_label.hide()
                sub_board_layout.addWidget(sub_board_label, 0, 0, 3, 3)
                self.sub_board_labels[row][col] = sub_board_label

                self.grid_layout.addWidget(sub_board, row, col)

    def highlight_available_moves(self):
        for row in range(self.board_size):
            for col in range(self.board_size):
                for sub_row in range(self.sub_board_size):
                    for sub_col in range(self.sub_board_size):
                        button = self.board[row][col][sub_row][sub_col]
                        if self.sub_board_status[row][col] is None and (
                                self.main_window.game_logic.next_board is None or self.main_window.game_logic.next_board == (row, col)) and button.text() == "":
                            button.setStyleSheet(f"font-size: 24px; background-color: {self.highlight_colour};")
                        else:
                            if button.text() == "X":
                                button.setStyleSheet(
                                    f"font-size: 24px; color: {self.colour_x}; background-color: {self.colour_main};")
                            elif button.text() == "O":
                                button.setStyleSheet(
                                    f"font-size: 24px; color: {self.colour_o}; background-color: {self.colour_main};")
                            else:
                                button.setStyleSheet(f"font-size: 24px; background-color: {self.colour_main};")

    def change_colour(self, element):
        colour = QColorDialog.getColor()
        if colour.isValid():
            if element == "X":
                self.colour_x = colour.name()
            elif element == "O":
                self.colour_o = colour.name()
            elif element == "main":
                self.colour_main = colour.name()
            elif element == "highlight":
                self.highlight_colour = colour.name()
            elif element == "background":
                self.background_colour = colour.name()
            self.highlight_available_moves()

    def update_sub_board(self, row, col, winner):
        self.sub_board_status[row][col] = winner
        self.sub_board_labels[row][col].setText(winner)
        self.sub_board_labels[row][col].setStyleSheet(
            f"color: {self.colour_x if winner == 'X' else self.colour_o};"
        )
        self.sub_board_labels[row][col].show()

        for sub_row in range(self.sub_board_size):
            for sub_col in range(self.sub_board_size):
                button = self.board[row][col][sub_row][sub_col]
                button.setText("")  # Clear the text of all buttons on the sub-board
                button.setVisible(True)  # Ensure all buttons on the sub-board are visible
                button.setEnabled(False)  # Disable all buttons on the sub-board

        self.highlight_available_moves()

    def reset_board(self):
        for row in range(self.board_size):
            for col in range(self.board_size):
                for sub_row in range(self.sub_board_size):
                    for sub_col in range(self.sub_board_size):
                        button = self.board[row][col][sub_row][sub_col]
                        button.setText("")
                        button.setEnabled(True)
                        button.setVisible(True)
                        button.setStyleSheet(f"font-size: 24px; background-color: {self.colour_main};")
                self.sub_board_labels[row][col].hide()
                self.sub_board_status[row][col] = None
        self.highlight_available_moves()
