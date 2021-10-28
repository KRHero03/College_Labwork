import sys

class ERRORS:
    INVALID_ARGS = """Invalid Arguments.\nPlease enter 2 Arguments which are Input File Path and Output File Path respectively."""

def perform_operation(input_file_path, output_file_path):
    """
    Reads input file, replaces consecutive spaces to a single space and writes to output file.
    """
    with open(input_file_path, 'r+') as input_file:
        with open(output_file_path, 'w') as output_file:
            output_file.write(" ".join(input_file.read().split()))

if __name__ == "__main__":
    if len(sys.argv) != 3:
        raise Exception(ERRORS.INVALID_ARGS)
    
    perform_operation(sys.argv[1], sys.argv[2])

    print("Operation completed.")
