# sample text : once upon a time there was a little girl named goldilocks she went for a walk in the forest pretty soon she came upon a house she knocked and when no one answered she walked right in at the table in the kitchen there were three bowls of porridge goldilocks was hungry she tasted the porridge from the first bowl
import time
import pickle
import random
import math


class ERRORS:
    """
    Error Messages
    """
    INVALID_CHOICE = "Please enter a valid Integer choice."
    INVALID_TEXT = "Please enter a valid Text. Text must only contain lowercase alphabets."
    INVALID_KEY = "Key needs to be one or more lowercase alphabets only."
# PROVABLEPRIME, Generation of provable primes with Maurer's algorithm, with
# illustrative coding of RSA encryption (with authentication) and digital
# signature for sequences of fixed-sized plaintext blocks and RSA PRBG.


# Prologue.


# Generation of large pseudo-random primes for use in public key processing has
# in the practice commonly been done with a probabilistic method based on a
# primality test due to Miller and Rabin [1, 2]. Though the method has a fairly
# simple algorithm, it leaves in our view yet something non-trivial to be
# desired due to the fact that, while one could rather efficiently achieve any
# arbitrarily small probability of error of the result in general, a
# theoretically 100% sure proof of its primaility couldn't be obtained thereby
# (We assume that in the Miller-Rabin test the bases employed are randomly
# chosen. cf. also [3].)
#
# [1] A. Menezes et al., Handbook of Applied Cryptography (HAC), p.139, CRC
#     Press, 5th printing 2011. Freely available: http://cacr.uwaterloo.ca/hac/
# [2} J. Pieprzyk et al., Fundamentals of Computer Security, pp.179-180, Berlin,
#     2003.
# [3] F. Arnaut, Rabin-Miller Test: Composite Numbers which Pass It, Math.
#     Comp., vol. 64, pp.355-361, 1995.

# A practical algorithm of generation of large pseudo-random primes that are
# provably prime is due to Maurer [4]. To our knowledge, to this day no
# implementation of it in any popular programming languages is yet available to
# the public. Since Maurer's algorithm not only has the virtue of delivering
# provable primes but is also in processing time well comparable to the
# algorithm based on the Miller-Rabin test (for sizes of primes of practical
# interest, see comparison below), we have coded it in Python according to its
# description in [1, p.153]. It is hoped that the present code, being easily
# readable and thus simply verifiable to be correct, could be well useful to
# those who desire to develop for themselves certain unconditionally required
# parts of public key security software entirely independent of the currently
# existing risky huge, open-source (and certainly any non-open-soruce) PKI
# packages. See Epilogue at the end of this document for a discussion of such
# risks, where a simple yet practically impossible to be detected method of
# embdding a backdoor into RSA non-open-source software is detailed. (In fact,
# a strong personal desire of freedom from dependencies on the existing risky
# PKI packages and of exclusive usage of codes that he can really read,
# understand and verify in all details has motivated the present author to write
# this package.) In this connection particular attention may be called to the
# fact that A. K. Lenstra et al. in an extensive examination of the RSA moduli
# used in practice (http://infoscience.epfl.ch/record/174943/files/eprint.pdf,
# p.10) wrote that they "could not explain the relative frequencies and
# appearance of the occurrence of duplicate RSA moduli and depth one trees"
# found in their study. One highly possible cause would apparently be backdoors
# in the software being employed for RSA key generations. (See also my post on
# security risks of shared prime factors among RSA moduli employed in practice:
# http://s13.zetaboards.com/Crypto/topic/7487358/1/)
#
# [4] U. Maurer, Fast Generation of Prime Numbers and Secure Public-key
#     Cryptographic Parameters, J. Cryptology, 8(1955), 123-155.

# Note that most of the complex and/or very poorly documented components of the
# existing PKI packages are irrelevant for our targeted users, the common
# people, who mostly need only straightforward encryption and (less frequently)
# digital signature processing on relatively low volume stuffs, and (perhaps
# very rarely) pseudo-random bit sequences, and that these really necessary
# tasks have been successfully implemented in our illustrative Example 3, 4, 3S
# and 5 further below with entirely acceptable runtime efficiency.

# The following examples of use of provableprime() are given in the Appendix,
# which are followed by a test of Python's PRNG (using system randomness).
# Ex. 3S should be highly useful for our target users, since it is presumably
# the normal case that both communication partners have public keys.
#
# Example 1: Generation of a pseudo-random provable prime of desired size.
#
# Example 2: Generation of RSA keys (satisfying certain desirable constraints).
#
# Example 3: RSA block encryption processing with authentication (integrity
#            check).
#
# Example 4: RSA digital signature processing.
#
# Example 3S: RSA block encryption processing with authentication (integrity
#             check) and signature of the sender.
#
# Example 5: RSA pseudo-random bit generation.
#
# For each example, cpu time measurement is done.


# Sketch of some major components of this software:

# provableprime(): This is the kernel of this software. See above.

# rsakeygeneration(): Generates RSA public and private keys (with
# consideration of recommendationns of a report of ENISA on key sizes and
# parameters).

# encrypttoct(): Encrypts a sequence of blocks of constant size of mb bits,
# on the one side applying the for RSA known method of transformation
# on the individual blocks, on the other side using certain commonly in
# symmetric block encryption employed methods, namely plaintext-and-ciphertext-
# block-chaining (with a pseudo-random IV). A sequence of blocks that stems from
# the plaintext of the user can thus be encrypted with RSA. (Note that this is
# a direct encryption of plaintext material with the help of RSA and not an
# encryption of a key for e.g. AES with RSA and afterwards an encryption of the
# plaintext with AES). Based on this function are the functions
# rsaencryptplaintexttoct() and rsaencryptbytearraytoct(), which process a
# user-given plaintext string and byte sequence respectively.

# rsasigndocument(): Signs a document as follows: The document is first
# processed in the same way as above for encryption and then the IV used
# therein and the last chaining-value obtained are transformed with RSA using
# the private key of the person who signs. The pair of the resulting two
# numbers serves as the signature of the document.

# rsaprbggenbits(): Generates a cryptographically secure pseudo-random bit
# sequence with RSA.

# It may be particularly stressed that (see also Epilogue):

# (1) This software is self-sufficient to be employed for the purpose of
# end-to-end encryption-protected communications of the common people. See
# Example 3 and 3S further below. It does not involve hash-functions, nor need
# additional use of any symmetric encryption software like AES, though multiple
# encryption, i.e. protected transfer with it of already otherwise encrypted
# materials, can of course be done, if desired. (cf. e.g. packages like PGP in
# which, besides RSA (or ElGamal), algorithms of IDEA and SHA (or their
# alternatives) are involved and which have further a huge volume of codes to be
# examined and consequently, being practically inconvenient or impossible for
# independent experts to closely examine, are a significant source of security
# risks, as recent history of commonly employed PKI software has clearly shown.)
# Hence for communications of n persons only n RSA private keys need to be
# securely guarded secret. Measurement showed that, with the parameter values
# employed in Example 3S, the encryption and decryption cpu times on a common PC
# for a message of 10000 characters are 2 and 4 sec respectively, which is
# evidently acceptable for our targeted users, the common people.

# (2) For a sufficiently small group of persons who (transitively) know one
# another well: (a) Ensuring the genuineness of the RSA public keys is
# generally not a problem and hence no CA is needed for that. The public keys
# could namely be either directly physically transferred or e.g. sent as
# hex-sequences via email and verified over a voice channel. (b) For eventuall
# needs of CA-functionalities one person could serve as CA, employing digital
# signature as given in Example 4 further below.

# (3) Since for our targeted users it is very likely the case that sender and
# receiver of messages both have public keys, Example 3S should be of
# significant value to their communications.

# The following is a comparison of average runtime in sec. on a common PC of
# generation of primes of different bit sizes with the function provableprime()
# further below and with the commonly employed probabilistic procedure, i.e.
# generating a random odd number and testing it for primality first via trial
# division by an appropriate set of small primes and then via the Miller-Rabin
# test for diverse values of t (on failure either increment the number by 2 or
# generate a new random odd number and continue the trial):
#
# bits   provp    t=1    t=2    t=3    t=4    t=5    t=10   t=20   t=30   t=40
#
#  500   0.073   0.040  0.042  0.044  0.045  0.046  0.050  0.059  0.074  0.085
#
# 1000   0.494   0.313  0.335  0.347  0.352  0.366  0.383  0.436  0.534  0.578
#
# 1500   1.851   1.104  1.168  1.181  1.241  1.334  1.450  1.513  1.791  1.940
#
# 2000   5.080   3.169  3.253  3.342  3.495  3.610  3.779  4.044  4.362  4.952
#
# This indicates that Maurer's algorithm could be fairly competitive with the
# probabilistic procedure in processing speed for higher values of t of the
# Miller-Rabin test. (Presumably this is also true for implementatons in other
# programming languages.)

# The software is written with priority being given to ease of understanding by
# persons new to Python (and eventual porting to other PLs) rather than to
# elegance of coding and optimal processing speed.

# It may be remarked that the kernel of this software, provableprime(), together
# with functions it depends on, has a total number of code lines of 123 only.
# All the rest are either code lines for the examples or are comment lines.


# Version 2.1, released on 13.03.2016.

# Update notes:

# Version 1.0: Released on 03.09.2014.
#
# Version 1.0.1: 18.09.2014: Addition of four functions to write to and read
# from files as convenience utilities.

# Version 1.1: 10.10.2014: Addition of Example 5 (RSA PRBG) and modification of
# plaintextstringtopt() to provide pseudo-random padding in Example 3.

# Version 1.1.1: 05.11.2014 : Modification of codes of Example 3 such that it
# can encrypt either a plaintext string or a byte sequence.

# Version 1.1.2: 03.12.2014: Improvement of a function used in the illustrative
# Example 3 and 4.

# Version 1.1.3: 15.07.2015: Removal of tiny coding redundancies.

# Version 1.2: 03.09.2015: Use of Python's SystemRandom class for random number
# generation.

# Version 1.2.1: 04.10.2015: Addition of a few checks of some user parameter
# input values.

# Version 1.2.2: 30.11.2015: Addition of checks in rsaprbgmodulusgeneration().

# Version 1.2.3: 01.12.2015: Improvement of rsaprbgmodulusgeneration().

# Version 2.0: 10.03.2016: Addition of Example 3S, RSA block encryption with
# authentication and signature. Addition of a check into provableprime().

# Version 2.1: 13.03.2016: Modification of provableprime() to render a check
# unnecessary.


# Code lines of documents with the same version number are always identical.
# There may be interim modifications of comment lines. The most recent document
# of PROVABLEPRIME can be obtained from:
# http://s13.zetaboards.com/Crypto/topic/7234475/1/


# This software may be freely used:

# 1. for all personal purposes unconditionally and

# 2. for all other purposes under the condition that its name, version number
#    and authorship are explicitly mentioned and that the author is informed of
#    all eventual code modifications done.


# The author is indebted to TPS for review and suggestions throughout
# PROVABLEPRIME's development phase. Thanks are also due to CWL whose comments
# led to the enhancements in Version 2.0. Any remaining deficiencies of the
# software are however the sole responsibilty of the author.

# Constructive critiques, comments and suggestions of extensions and
# improvements are sincerely solicited. Address of the author:
#
# Email: mok-kong.shen@t-online.de
#
# Mail: Mok-Kong Shen, Postfach 340238, Munich 80099, Germany
#
# (Sender data optional, if no reply is required.)


################################################################################


# The Euclidean algorithm for gcd.

def gcd(a, b):
    while a != 0:
        a, b = b % a, a
    return(b)


# Find the inverse of a mod n, cf. Wiki, Extended Euclidean algorithm.

def modinv(a, n):
    t, nt = 0, 1
    r, nr = n, a
    while nr != 0:
        q = r//nr
        t, nt = nt, t-q*nt
        r, nr = nr, r-q*nr
    if r > 1:
        return None
    while t < 0:
        t += n
    return(t)


# The initial constellation of the table of small primes.

ptab = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71]


# ptab, the table of small primes, will be extended, if necessary, to have its
# last element not less than trialdivbound. (Sieve of Eratosthenes is used.)

def checkptab(trialdivbound):
    global ptab
    g = ptab[-1]
    while ptab[-1] < trialdivbound:
        g += 2
        h = math.ceil(math.sqrt(g))
        for p in ptab:
            if p > h:
                suc = 1
                break
            if (g % p) == 0:
                suc = 0
                break
        if suc == 0:
            continue
        ptab += [g]
    return


# We extend ptab by default to a size appropriate for primality test with trial
# division for numbers up to 20 bits (this is required in the first part of the
# function provableprime() further below).

checkptab(2**10)


# Apply t rounds of the Miller-Rabin test to n.
#
# Return value: 0: n is composite.
#
#               1: n passes t rounds of the strong probable prime test.
#
# Set kn=1, if the first round is to use a=2, else set kn=0.
#
# See [1, p.139].
#
# We use this test only to improve the efficiency of Maurer's algorithm, see
# comments in provableprime() futher below.

def millerrabin(n, t, kn):
    assert t >= 1 and 0 <= kn <= 1
    if n <= 3:
        if n > 1:
            return(1)
        return(0)
    elif n % 2 == 0:
        return(0)
    RANDOM = random.SystemRandom()
    r = n1 = n-1
    s = 0
    while (r % 2) > 0:
        s += 1
        r //= 2
    s1 = s-1
    for i in range(t):
        if i == 0 and kn == 1:
            a = 2
        else:
            a = RANDOM.randint(2, n-2)
        y = pow(a, r, n)
        if y != 1 and y != n1:
            j = 1
            while j <= s1 and y != n1:
                y = (y*y) % n
                if y == 1:
                    return(0)
                j += 1
            if y != n1:
                return(0)
    return(1)


# Generate a random odd number n (2**k > n > 2**(k-1), k >= 2) with proveable
# primality employing Maurer's algorithm (the (k-1)-th bit of n is 1).
# Cf. sec.4.62 of HAC [1, p.153].

def provableprime(k):
    global ptab
    RANDOM = random.SystemRandom()
# The default size of ptab (see above) is sufficiently large for cases k<=20.
    if k <= 20:
        while True:
            # Select a random odd integer in the interval [2**(k-1), 2**k-1] (A. J. Menezes,
            # personal communication).
            n = RANDOM.randint(2**(k-1), 2**k-1) | 1
            h = math.ceil(math.sqrt(n))
            for p in ptab[1:]:
                if p > h:
                    return(n)
                if (n % p) == 0:
                    break
# We use c=0.005 which has been experimentally found to be optimal in processing
# time for common PC under MS Windows and values of k of practical interest.
# A different c value may be desirable for use in different computing
# environments.
    c = 0.005
    bb = math.ceil(c*k*k)
    checkptab(bb)
    m = 20
    if k > 2*m:
        while True:
            s = RANDOM.uniform(0, 1)
            r = 2**(s-1)
            if (k-r*k) > m:
                break
    else:
        r = 0.5
    q = provableprime(math.floor(r*k)+1)
    ii = 2**(k-1)//(2*q)
    success = 0
    while success == 0:
        rr = RANDOM.randint(ii+1, 2*ii)
        n = 2*rr*q+1
        suc = 1
        for p in ptab:
            if p > bb:
                break
            if (n % p) == 0:
                suc = 0
                break
        if suc == 0:
            continue
# See [1, p.153, 4.6.3 (ii)], Miller-Rabin test is employed here for purposes of
# improvement of efficiency only.
        if millerrabin(n, 1, 1) == 1:
            a = RANDOM.randint(2, n-2)
            if pow(a, n-1, n) == 1:
                b = pow(a, 2*rr, n)
                if gcd(b-1, n) == 1:
                    success = 1
    return(n)


################################################################################


# Installation of the software.

# Both communication partners have to download the same version 3x of Python
# from http://www.python.org. (Employing the same version of Python ensures
# against any potentially possible incompatibilities among different versions.)
# The present code can be stored in a file named e.g. provableprime.py and the
# examples given further below run in Python's GUI IDLE. (File --> Open to find
# and open the file, then in the window showing the code Run --> Run Module to
# run it. One could also type provableprime.py in a DOS-window.) Modifications
# of the code in the code window, e.g. the plaintext string, can be done online
# and the code re-run.


################################################################################
################################################################################
################### end of part 1 (of 4) of PROVABLEPRIME2.1 ###################

def rsa_cipher_encrypt(text: str) -> str:
    """
    RSA Cipher Encryption using Generated Key.
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


def rsa_cipher_decrypt(text: str, key: int):
    """
    RSA Cipher Decryption using given Key.
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


def rsa_cipher_encrypt_dialog():
    """
    Runs RSA Cipher Encryption Dialog
    """
    text = input("Enter text to be encrypted: ")

    encrypted_text = rsa_cipher_encrypt(text, key)

    print(f"Encrypted Text: {encrypted_text}")


def rsa_cipher_decrypt_dialog():
    """
    Runs RSA Cipher Decryption Dialog
    """
    text = input("Enter text to be decrypted: ")

    decrypted_text = rsa_cipher_decrypt(text)

    print(f"Decrypted Text: {decrypted_text}")


def main_dialog():
    """
    Runs main dialog sequence
    """
    try:
        choice = int(input(
            "RSA Cipher Program\n1. Encrypt\n2. Decrypt\nPlease enter your choice: "))
    except Exception as e:
        raise Exception(ERRORS.INVALID_CHOICE)

    if choice == 1:
        rsa_cipher_encrypt_dialog()
    elif choice == 2:
        rsa_cipher_decrypt_dialog()
    else:
        raise Exception(ERRORS.INVALID_CHOICE)


if __name__ == "__main__":
    try:
        main_dialog()
    except Exception as e:
        print(e)
