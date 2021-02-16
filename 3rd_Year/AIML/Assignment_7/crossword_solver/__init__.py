import copy
import numpy as np
import cv2


class CrosswordSolver:
    def __init__(self, rows: int, cols: int, verbose: int):
        self.rows = rows
        self.cols = cols
        self.matrix = [["#" for i in range(self.cols)] for j in range(self.rows)]
        self.ids = dict()
        self.list = list()
        self.verbose = verbose

        if self.verbose == 1:
            print("Initialised CrosswordSolver with parameters:")
            print("Rows:", self.rows)
            print("Cols:", self.cols)
            print("Verbose:", self.verbose)

        self.font = cv2.FONT_HERSHEY_SIMPLEX
        self.startImageWrite = (10, 50)
        self.fontScale = 1
        self.fontColor = (255, 255, 255)
        self.lineType = 2

    def block(self, row: int, col: int):
        self.matrix[row][col] = "-"
        if self.verbose == 1:
            print("Blocked", (row, col), "in the Base State!")

    def add_id(self, row: int, col: int, id: int):
        self.ids[id] = (row, col)
        if self.verbose == 1:
            print("Added ID at", (row, col), "with ID:", id)

    def add_word(self, id: int, direction: int, word: str):
        self.list.append((word, id, direction))
        if self.verbose == 1:
            print(
                "Added Word",
                word,
                "at ID",
                id,
                "in direction",
                ("Across" if direction == 0 else "Down"),
                "!",
            )

    def check_valid_insert(
        self, state: list(list()), id: int, direction: int, word: str
    ) -> bool:
        row, col = self.ids[id]

        if direction == 0:
            for i in range(col, col + len(word)):
                if i == self.cols:
                    return False
                if state[row][i] != "#" and state[row][i] != word[i - col]:
                    return False
        else:
            for i in range(row, row + len(word)):
                if i == self.rows:
                    return False
                if state[i][col] != "#" and state[i][col] != word[i - row]:
                    return False
        return True

    def insert_word(
        self, state: list(list()), id: int, direction: int, word: str
    ) -> list(list()):

        row, col = self.ids[id]

        new_state = copy.deepcopy(state)

        if direction == 0:
            for i in range(col, col + len(word)):
                new_state[row][i] = word[i - col]
        else:
            for i in range(row, row + len(word)):
                new_state[i][col] = word[i - row]
        return new_state

    def is_solved(self, state: list(list())) -> bool:

        for i in range(self.rows):
            for j in range(self.cols):
                if state[i][j] == "#":
                    return False
        return True

    def __visualise(self, state):
        if self.verbose == 1:
            strings = []

            for i in state:
                new_string = ""
                for j in i:
                    new_string += j + " "
                strings.append(new_string)

            img = np.zeros((50 * self.rows, 40 * self.cols, 3), np.uint8)
            offset = 0
            for i in strings:
                cv2.putText(
                    img,
                    i,
                    (self.startImageWrite[0], self.startImageWrite[1] + offset),
                    self.font,
                    self.fontScale,
                    self.fontColor,
                    self.lineType,
                )
                offset = offset + 40
            cv2.imshow("Image Visualization", img)
            cv2.waitKey(33)

    def solve(self):
        state = copy.deepcopy(self.matrix)
        solved_state, result = self.__solve_crossword(state, 0)
        if result == 0:
            return [[]]

        return solved_state

    def __solve_crossword(self, state: list(list()), word_idx: int):
        self.__visualise(state)
        if word_idx == len(self.list):
            if self.is_solved(state):
                return (state, 1)
            else:
                return (state, 0)

        word, id, direction = self.list[word_idx]

        if self.check_valid_insert(state, id, direction, word) == True:
            new_state = self.insert_word(state, id, direction, word)

            (solved_state, result) = self.__solve_crossword(new_state, word_idx + 1)

            if result == 1:
                return (solved_state, result)

        return self.__solve_crossword(state, word_idx + 1)
