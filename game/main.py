import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QGridLayout, QWidget, QPushButton, QMessageBox, QLabel, \
    QLineEdit, QVBoxLayout, QAction, QColorDialog, QFileDialog, QMenu
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QPixmap, QFont
from player_panel import PlayerPanel
from board import Board
from game_logic import GameLogic


class SuperTicTacToe(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("SUPER TIC-TAC-TOE")
        self.setGeometry(100, 100, 1200, 900)

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)

        self.main_layout = QGridLayout()
        self.central_widget.setLayout(self.main_layout)

        self.player1_panel = PlayerPanel(self, "Player 1")
        self.player2_panel = PlayerPanel(self, "Player 2")
        self.board = Board(self)
        self.game_logic = GameLogic(self.board)

        self.current_player_label = QLabel(f"Current Player: {self.game_logic.current_player}")
        self.current_player_label.setFont(QFont("Arial", 26))

        self.initUI()

    def initUI(self):
        self.main_layout.addLayout(self.player1_panel.layout, 0, 0, Qt.AlignTop)
        self.main_layout.addLayout(self.player2_panel.layout, 0, 2, Qt.AlignTop)
        self.main_layout.addLayout(self.board.grid_layout, 0, 1)
        self.main_layout.addWidget(self.current_player_label, 1, 1, Qt.AlignCenter)

        self.board.highlight_available_moves()

        menubar = self.menuBar()
        state_menu = menubar.addMenu("State")
        edit_menu = menubar.addMenu("Edit")

        load_action = QAction("Load", self)
        save_action = QAction("Save", self)
        state_menu.addAction(load_action)
        state_menu.addAction(save_action)
        load_action.triggered.connect(self.game_logic.load_game)
        save_action.triggered.connect(self.game_logic.save_game)

        colour_menu = QMenu("Change Colours", self)
        change_colour_x_action = QAction("Change X Colour", self)
        change_colour_o_action = QAction("Change O Colour", self)
        change_colour_main_action = QAction("Change Main Colour", self)
        change_highlight_colour_action = QAction("Change Highlight Colour", self)
        change_background_colour_action = QAction("Change Background Colour", self)

        colour_menu.addAction(change_colour_x_action)
        colour_menu.addAction(change_colour_o_action)
        colour_menu.addAction(change_colour_main_action)
        colour_menu.addAction(change_highlight_colour_action)
        colour_menu.addAction(change_background_colour_action)

        edit_menu.addMenu(colour_menu)

        change_colour_x_action.triggered.connect(lambda: self.board.change_colour("X"))
        change_colour_o_action.triggered.connect(lambda: self.board.change_colour("O"))
        change_colour_main_action.triggered.connect(lambda: self.board.change_colour("main"))
        change_highlight_colour_action.triggered.connect(lambda: self.board.change_colour("highlight"))
        change_background_colour_action.triggered.connect(lambda: self.board.change_colour("background"))

    def update_current_player_label(self):
        self.current_player_label.setText(f"Current Player: {self.game_logic.current_player}")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = SuperTicTacToe()
    window.show()
    sys.exit(app.exec_())
