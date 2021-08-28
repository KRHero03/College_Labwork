# sample text : once upon a time there was a little girl named goldilocks she went for a walk in the forest pretty soon she came upon a house she knocked and when no one answered she walked right in at the table in the kitchen there were three bowls of porridge goldilocks was hungry she tasted the porridge from the first bowl

from typing import OrderedDict
import math
from itertools import chain

PLACEHOLDER = "#"


class ERRORS:
    KEY_LENGTH = "Invalid Key! Key Length should be more than 1!"
    KEY_UNIQUE_CHARACTERS = "Invalid Key! Key characters should be unique!"
    CHOICE = "Please enter a valid choice!"


def columnar_transposition_cipher_encrypt(text: str, key: str) -> str:
    """
    Encrypts the given text using Key using Columnar Transposition Cipher Encryption
    """
    if len(key) <= 1:
        raise Exception(ERRORS.KEY_LENGTH)
    key_mapping = OrderedDict()
    for i in range(len(key)):
        if key[i] in key_mapping:
            raise Exception(ERRORS.KEY_UNIQUE_CHARACTERS)
        key_mapping[key[i]] = i

    final_row = int(math.ceil(len(text)/len(key)))
    character_matrix = [[PLACEHOLDER for _ in range(
        len(key))] for _ in range(final_row)]

    for i in range(len(text)):
        row = i//len(key)
        col = i % len(key)
        character_matrix[row][col] = text[i]

    encrypted_char_list = []
    for key in sorted(key_mapping):
        col = key_mapping[key]
        for row in range(final_row):
            encrypted_char_list.append(character_matrix[row][col])

    return "".join(encrypted_char_list)


def columnar_transposition_cipher_decrypt(text: str, key: str) -> str:
    """
    Decrypts the given text using Key using Columnar Transposition Cipher Decryption
    """
    if len(key) <= 1:
        raise Exception(ERRORS.KEY_LENGTH)
    key_mapping = OrderedDict()
    for i in range(len(key)):
        if key[i] in key_mapping:
            raise Exception(ERRORS.KEY_UNIQUE_CHARACTERS)
        key_mapping[key[i]] = i

    final_row = int(math.ceil(len(text)/len(key)))
    character_matrix = [[PLACEHOLDER for _ in range(
        len(key))] for _ in range(final_row)]

    text_char_pos = 0
    for key in sorted(key_mapping):
        col = key_mapping[key]
        for row in range(final_row):
            character_matrix[row][col] = text[text_char_pos]
            text_char_pos += 1

    return "".join(list(chain.from_iterable(character_matrix))).replace(PLACEHOLDER, "")


def run_columnar_transposition_cipher_encrypt_dialog():
    """
    Runs dialog to facilitate Columnar Transposition Cipher Encryption
    """
    text = input("Please enter Text : ")
    key = input("Please enter Key : ")
    encrypted_text = columnar_transposition_cipher_encrypt(text, key)
    print(f"Encrypted Text : {encrypted_text}")
    pass


def run_columnar_transposition_cipher_decrypt_dialog():
    """
    Runs dialog to facilitate Columnar Transposition Cipher Decryption
    """
    text = input("Please enter Text : ")
    key = input("Please enter Key : ")
    decrypted_text = columnar_transposition_cipher_decrypt(text, key)
    print(f"Decrypted Text : {decrypted_text}")
    pass


def run_menu():
    """
    Runs menu
    """
    try:
        choice = int(input(
            "Columnar Transposition Cipher\n1. Encrypt Text\n2. Decrypt Text\nEnter your choice : "))
        if choice not in (0, 1, 2):
            raise Exception(ERRORS.CHOICE)
    except Exception as e:
        print(f"Failed to run Program. Error : {e}")
        return

    try:
        if choice == 1:
            run_columnar_transposition_cipher_encrypt_dialog()
        elif choice == 2:
            run_columnar_transposition_cipher_decrypt_dialog()
    except Exception as e:
        print(f"Failed to run Program. Error : {e}")
        return


if __name__ == "__main__":
    run_menu()
