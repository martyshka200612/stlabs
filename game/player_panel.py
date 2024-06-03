from PyQt5.QtWidgets import QVBoxLayout, QLabel, QLineEdit, QPushButton, QFileDialog
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import Qt


class PlayerPanel:
    def __init__(self, main_window, player_name):
        self.main_window = main_window
        self.player_name = player_name
        self.photo_path = "default_photo.jpg"
        self.photo_size = 360

        self.layout = QVBoxLayout()
        self.initUI()

    def initUI(self):
        self.name_edit = QLineEdit(self.player_name)
        self.photo_label = QLabel()
        self.photo_label.setPixmap(QPixmap(self.photo_path).scaled(self.photo_size, self.photo_size, Qt.KeepAspectRatio))

        upload_photo_button = QPushButton("Upload Photo")
        upload_photo_button.clicked.connect(self.upload_photo)

        remove_photo_button = QPushButton("Remove Photo")
        remove_photo_button.clicked.connect(self.remove_photo)

        self.layout.addWidget(QLabel(f"{self.player_name}:"))
        self.layout.addWidget(self.name_edit)
        self.layout.addWidget(self.photo_label)
        self.layout.addWidget(upload_photo_button)
        self.layout.addWidget(remove_photo_button)

    def upload_photo(self):
        options = QFileDialog.Options()
        file_name, _ = QFileDialog.getOpenFileName(self.main_window, "Select Photo", "", "Image Files (*.png *.jpg *.bmp)",
                                                   options=options)
        if file_name:
            pixmap = QPixmap(file_name).scaled(self.photo_size, self.photo_size, Qt.KeepAspectRatio)
            self.photo_path = file_name
            self.photo_label.setPixmap(pixmap)

    def remove_photo(self):
        pixmap = QPixmap("default_photo.jpg").scaled(self.photo_size, self.photo_size, Qt.KeepAspectRatio)
        self.photo_path = "default_photo.jpg"
        self.photo_label.setPixmap(pixmap)
