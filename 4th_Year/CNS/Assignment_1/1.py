# Sample Text : once upon a time there was a little girl named goldilocks she went for a walk in the forest pretty soon she came upon a house she knocked and when no one answered she walked right in at the table in the kitchen there were three bowls of porridge goldilocks was hungry she tasted the porridge from the first bowl

THEORETICAL_FREQUENCY = {"e": 12.7, "t": 9.06, "a": 8.17, "o": 7.51, "i": 6.97, "n": 6.75, "s": 6.33, "h": 6.09, "r": 5.99, "d": 4.25, "l": 4.02, "c": 2.78,
                         "u": 2.76, "m": 2.41, "w": 2.36, "f": 2.23, "g": 2.01, "y": 1.97, "p": 1.93, "b": 1.49, "v": 0.99, "k": 0.77, "j": 0.15, "x": 0.15, "q": 0.09, "z": 0.07}
FREQUENCY_ANALYSIS_ALPHABETS = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                                "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]


def encrypt(text: str, key: int) -> str:
    """
    Encrypts text by shifting characters by key
    Text contains only alphabetical characters and spaces
    """
    ciphertext = ""
    for char in text:
        if char.isalpha():
            ciphertext += (
                chr((ord(char) - ord("a") + key) % 26 + ord("a"))
                if ord(char) >= ord("a")
                else chr((ord(char) - ord("A") + key) % 26 + ord("A"))
            )
        else:
            ciphertext += char
    return ciphertext


def decrypt(text: str, key: int) -> str:
    """
    Decrypts text by shifting characters by key towards the left
    Text contains only alphabetical characters and spaces
    """
    ciphertext = ""
    for char in text:
        if char.isalpha():
            ciphertext += (
                chr((ord(char) - ord("a") - key + 26) % 26 + ord("a"))
                if ord(char) >= ord("a")
                else chr((ord(char) - ord("A") - key + 26) % 26 + ord("A"))
            )
        else:
            ciphertext += char
    return ciphertext


def frequency_analysis_decrypt(text: str) -> str:
    """
    Runs frequency analysis decryption on text to find out valid key and decrypted text
    Returns tuple (key,decrypted_text) 
    """
    TEXT_LENGTH = len(text)
    final_error = 100000000
    final_key = 0
    for key in range(0, 26):
        actual_frequency = {}
        decrypted_text = decrypt(text, key)
        for character in decrypted_text:
            if character == " " or character not in FREQUENCY_ANALYSIS_ALPHABETS:
                if character == " ":
                    continue
                raise Exception(
                    "Invalid character found in given encrypted text!")
            actual_frequency[character] = actual_frequency.get(
                character, 0) + 1
        # RMSE 
        error = sum([(THEORETICAL_FREQUENCY.get(character, 0) - (100*(actual_frequency.get(
            character, 0)/TEXT_LENGTH)))**2 for character in FREQUENCY_ANALYSIS_ALPHABETS])
        error /= 26
        error **= 0.5
        if error < final_error:
            final_key = key
            final_error = error

    return final_key, decrypt(text, final_key)


def run_encrypt_dialog():
    """
    Runs menu for encryption dialog
    """
    text = input("Please enter a text to encrypt: ")
    key = int(input("Please enter a key: "))
    if key <= 0 and key >= 26:
        raise Exception("Please enter a key between 1 and 25 only!")
    print("Your encrypted text is: " + encrypt(text, key))


def run_decrypt_dialog():
    """
    Runs menu for decrypt dialog
    """
    text = input("Please enter a text to decrypt: ")
    try:
        key = int(input("Please enter a key: "))
    except:
        raise Exception("Please enter a valid key!")
    if key <= 0 or key >= 26:
        raise Exception("Please enter a key between 1 and 25 only!")
    print("Your decrypted text is: " + decrypt(text, key))


def run_brute_force_decrypt_dialog():
    """
    Prints result after using all the possible values of Key for given decrypted text
    """
    text = input("Please enter a text to decrypt: ")

    for key in range(0, 26):
        print(f"Key #{key}: {decrypt(text,key)}")


def run_frequency_analysis_decrypt_dialog():
    """
    Prints key and decrypted text after using frequency analysis for given decrypted text
    """
    text = input(
        "Please enter a text to decrpyt( Only Lowercase Alphabets and Space allowed) :")

    key, decrypted_text = frequency_analysis_decrypt(text)

    print(f"Expected Key #{key} : {decrypted_text}")


def run_menu_loop():
    """
    Runs menu loop
    """
    try:
        choice = -1
        try:
            choice = int(
                input("1. Encrypt\n2. Decrypt\n3. Brute Force Attack\n4. Frequency Analysis Decryption\n0. Exit\nPlease enter your choice: ")
            )
        except:
            raise Exception("Please enter a valid Integer Choice!")
        if choice == 1:
            run_encrypt_dialog()
        elif choice == 2:
            run_decrypt_dialog()
        elif choice == 3:
            run_brute_force_decrypt_dialog()
        elif choice == 4:
            run_frequency_analysis_decrypt_dialog()
        elif choice == 0:
            return
        else:
            print("Invalid choice!")
    except Exception as e:
        print(e)

if __name__ == "__main__":
    run_menu_loop()
