import os
import random
import hashlib

P = None
Q = None
G = None
X = None
Y = None

LOW_PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443,
                  449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]

USER = "Obito"  
FILE = "test_input.txt"

def is_prime(n):
    """
    Checks if a number is prime
    """
    
    if n in LOW_PRIMES:
        return True
    
    for prime in LOW_PRIMES:
        if n%prime == 0:
            return False
    
    d = n - 1
    s = 0
    while d % 2 == 0:
        d //= 2
        s += 1
    
    for _ in range(128):
        a = random.randrange(2, n - 1)
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(s - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                p = 1
                break
        else:
            return False
    return True




def generate_large_prime(bit_size):
    """
    Generates a large prime number of bit_size bits
    """
    while True:
        p = random.randint(2**(bit_size-1),2**bit_size)
        if is_prime(p):
            return p

def generate_unique_divisible_prime(q):
    """
    Generates a unique divisible prime number
    """
    while True:
        k = random.randint(2**(456-1),2**456)
        p = k*q + 1
        if is_prime(p):
            return p

def initialize_system():
    """
    Creates P,Q,G and stores it in system file in the same directory
    """
    global P,Q,G
    if os.path.exists("system"):
        print("System file already exists")
        with open("system","r") as f:
            P = int(f.readline())
            Q = int(f.readline())
            G = int(f.readline())        
        print("P:",P)
        print("Q:",Q)
        print("G:",G)
        return
    
    Q = generate_large_prime(160)
    P = generate_unique_divisible_prime(Q)

    h = random.randint(2,P-2)  
    G = 1
    while G == 1:
        G = pow(h,(P-1)//Q,P) 
    
    with open("system","w") as f:
        f.write(str(P)+"\n")
        f.write(str(Q)+"\n")
        f.write(str(G)+"\n")
    print("Created System file")
    print("P:",P)
    print("Q:",Q)
    print("G:",G)

def generate_user():
    """
    Generates X,Y pair for user and store it in user file
    """
    global P,Q,G,X,Y
    if os.path.exists(USER):
        print("User file already exists")
        with open(USER,"w") as f:
            X = int(f.readline())
            Y = int(f.readline())
        print("X:",X)
        print("Y:",Y)
        return
    
    X = random.randint(1,Q-1)
    Y = pow(G,X,P)

    with open(USER,"w") as f:
        f.write(str(X)+"\n")
        f.write(str(Y)+"\n")
    print("Created User file")
    print("X:",X)
    print("Y:",Y)

def create_signature():
    """
    Creates signature for user and stores (r,s) into file
    """
    global P,Q,G,X,Y
    with open(USER,"r") as f:
        X = int(f.readline())
        Y = int(f.readline())
    k = random.randint(1,Q-1)

    with open(FILE, "rb") as file:
        file_hash = hashlib.sha256(file.read()).hexdigest()
        file_hash_int = int(file_hash, 16) #H(M)

    r = pow(G,k,P) % Q
    k_inv = pow(k,Q-2,Q)
    s = (k_inv * (file_hash_int + X*r)) % Q

    with open("signature.sig","w") as f:
        f.write(str(r)+"\n")
        f.write(str(s)+"\n")
    
    print("Signature created!")

def verify_signature():
    """
    Verifies signature of user
    """
    global P,Q,G,X,Y
    with open(USER,"r") as f:
        _ = int(f.readline())
        Y = int(f.readline())
    with open("signature.sig","r") as f:
        r = int(f.readline())
        s = int(f.readline())
    with open(FILE, "rb") as file:
        file_hash = hashlib.sha256(file.read()).hexdigest()
        file_hash_int = int(file_hash, 16) #H(M)
    
    w = pow(s,Q-2,Q)
    u_1 = (file_hash_int * w) % Q
    u_2 = (r * w) % Q
    v = ((pow(G,u_1,P) * pow(Y,u_2,P)) % P) % Q

    if v == r:
        print("Signature Verified!")
    else:
        print("Signature Invalid!")

if __name__ == "__main__":
    try:
        initialize_system()
        generate_user()
        # create_signature()
        verify_signature()
    except Exception as e:
        print(e)