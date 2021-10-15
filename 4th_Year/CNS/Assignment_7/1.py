# sample text : once upon a time there was a little girl named goldilocks she went for a walk in the forest pretty soon she came upon a house she knocked and when no one answered she walked right in at the table in the kitchen there were three bowls of porridge goldilocks was hungry she tasted the porridge from the first bowl
class ERRORS:
    """
    Error Messages
    """
    INVALID_CHOICE = "Please enter a valid Integer choice."
    INVALID_TEXT = "Please enter a valid Text. Text must only contain lowercase alphabets."
    INVALID_KEY = "Key needs to be one or more lowercase alphabets only."


def vigenere_cipher_encrypt(text: str, key: str) -> str:
    """
    Vigenere Cipher Encryption using Key.
    Returns:
        Encrypted Text
    """
    for c in key:
        if ord(c) < 97 or ord(c) > 122:
            raise Exception(ERRORS.INVALID_KEY)

    if len(key) == 0:
        raise Exception(ERRORS.INVALID_KEY)

    for c in text:
        if (ord(c) < 97 or ord(c) > 122) and c != " ":
            raise Exception(ERRORS.INVALID_TEXT)

    encrypted_chars = []

    for i in range(len(text)):
        if text[i] == " ":
            encrypted_chars.append(" ")
        else:
            encrypted_chars.append(
                chr(((ord(text[i]) - 97 + ord(key[i % len(key)]) - 97) % 26) + 97))

    return "".join(encrypted_chars)


def vigenere_cipher_decrypt(text: str, key: int):
    """
    Vigenere Cipher Decryption using given Key.
    Returns:
        Decrypted Text
    """
    for c in key:
        if ord(c) < 97 or ord(c) > 122:
            raise Exception(ERRORS.INVALID_KEY)

    if len(key) == 0:
        raise Exception(ERRORS.INVALID_KEY)

    for c in text:
        if (ord(c) < 97 or ord(c) > 122) and c != " ":
            raise Exception(ERRORS.INVALID_TEXT)

    decrypted_chars = []

    for i in range(len(text)):
        if text[i] == " ":
            decrypted_chars.append(" ")
        else:
            decrypted_chars.append(
                chr(((ord(text[i]) - 97 - (ord(key[i % len(key)]) - 97) + 26) % 26) + 97))

    return "".join(decrypted_chars)


def vigenere_cipher_encrypt_dialog():
    """
    Runs Vigenere Cipher Encryption Dialog
    """
    text = input("Enter text to be encrypted: ")
    key = input("Enter key: ")

    encrypted_text = vigenere_cipher_encrypt(text, key)

    print(f"Encrypted Text: {encrypted_text}")


def vigenere_cipher_decrypt_dialog():
    """
    Runs Vigenere Cipher Decryption Dialog
    """
    text = input("Enter text to be decrypted: ")
    key = input("Enter key: ")

    decrypted_text = vigenere_cipher_decrypt(text, key)

    print(f"Decrypted Text: {decrypted_text}")


def main_dialog():
    """
    Runs main dialog sequence
    """
    try:
        choice = int(input(
            "Vigenere Cipher (One Time Pad) Program\n1. Encrypt\n2. Decrypt\nPlease enter your choice: "))
    except Exception as e:
        raise Exception(ERRORS.INVALID_CHOICE)

    if choice == 1:
        vigenere_cipher_encrypt_dialog()
    elif choice == 2:
        vigenere_cipher_decrypt_dialog()
    else:
        raise Exception(ERRORS.INVALID_CHOICE)


if __name__ == "__main__":
    try:
        main_dialog()
    except Exception as e:
        print(e)
