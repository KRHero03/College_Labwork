# sample text : once upon a time there was a little girl named goldilocks she went for a walk in the forest pretty soon she came upon a house she knocked and when no one answered she walked right in at the table in the kitchen there were three bowls of porridge goldilocks was hungry she tasted the porridge from the first bowl

from typing import OrderedDict

PLACEHOLDER = "#"


class ERRORS:
    KEY_LENGTH = "Invalid Key! Key Length should be more than 1!"
    KEY_UNIQUE_CHARACTERS = "Invalid Key! Key characters should be unique!"
    CHOICE = "Please enter a valid choice!"


def rail_fence_transposition_cipher_encrypt(text: str, key: str) -> str:
    """
    Encrypts the given text using Key using Rail Fence Transposition Cipher Encryption
    """
    if len(key) <= 1:
        raise Exception(ERRORS.KEY_LENGTH)
    key_mapping = OrderedDict()
    for i in range(len(key)):
        if key[i] in key_mapping:
            raise Exception(ERRORS.KEY_UNIQUE_CHARACTERS)
        key_mapping[key[i]] = i

    final_row = len(key)
    character_matrix = []

    gap1 = 2*final_row - 2
    gap2 = 0
    for i in range(final_row):
        text_pos = i
        check = 0
        character_row = []
        while text_pos < len(text):
            character_row.append(text[text_pos])
            if check:
                text_pos += gap2 if gap2 != 0 else 2*final_row - 2
            else:
                text_pos += gap1 if gap1 != 0 else 2*final_row - 2
            check ^= 1
        character_matrix.append(character_row)
        gap1 -= 2
        gap2 += 2

    encrypted_char_list = []
    for key in sorted(key_mapping):
        row = key_mapping[key]
        for value in character_matrix[row]:
            encrypted_char_list.append(value)

    return "".join(encrypted_char_list)


def rail_fence_transposition_cipher_decrypt(text: str, key: str) -> str:
    """
    Decrypts the given text using Key using Rail Fence Transposition Cipher Decryption
    """
    if len(key) <= 1:
        raise Exception(ERRORS.KEY_LENGTH)
    key_mapping = OrderedDict()
    for i in range(len(key)):
        if key[i] in key_mapping:
            raise Exception(ERRORS.KEY_UNIQUE_CHARACTERS)
        key_mapping[key[i]] = i

    final_row = len(key)
    decrypted_text = [PLACEHOLDER for _ in range(len(text))]
    row_order = [key_mapping[key] for key in sorted(key_mapping)]
    pos = 0
    for i in row_order:
        gap1 = 2*final_row - 2*(i+1)
        gap2 = 2*i
        text_pos = i
        check = 0
        while text_pos < len(text):
            decrypted_text[text_pos] = text[pos]
            if check:
                text_pos += gap2 if gap2 != 0 else 2*final_row - 2
            else:
                text_pos += gap1 if gap1 != 0 else 2*final_row - 2
            check ^= 1
            pos += 1
    
    return "".join(decrypted_text)

   


def run_rail_fence_transposition_cipher_encrypt_dialog():
    """
    Runs dialog to facilitate Rail Fence Transposition Cipher Encryption
    """
    text = input("Please enter Text : ")
    key = input("Please enter Key : ")
    encrypted_text = rail_fence_transposition_cipher_encrypt(text, key)
    print(f"Encrypted Text : {encrypted_text}")
    pass


def run_rail_fence_transposition_cipher_decrypt_dialog():
    """
    Runs dialog to facilitate Rail Fence Transposition Cipher Decryption
    """
    text = input("Please enter Text : ")
    key = input("Please enter Key : ")
    decrypted_text = rail_fence_transposition_cipher_decrypt(text, key)
    print(f"Decrypted Text : {decrypted_text}")
    pass


def run_menu():
    """
    Runs menu
    """
    try:
        choice = int(input(
            "Rail Fence Transposition Cipher\n1. Encrypt Text\n2. Decrypt Text\nEnter your choice : "))
        if choice not in (0, 1, 2):
            raise Exception(ERRORS.CHOICE)
    except Exception as e:
        print(f"Failed to run Program. Error : {e}")
        return

    try:
        if choice == 1:
            run_rail_fence_transposition_cipher_encrypt_dialog()
        elif choice == 2:
            run_rail_fence_transposition_cipher_decrypt_dialog()
    except Exception as e:
        print(f"Failed to run Program. Error : {e}")
        return


if __name__ == "__main__":
    run_menu()
