#!/opt/homebrew/bin/python3
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import padding


import sys, os

if (len(sys.argv)) != 2:
    print ('Usage: ./capstone.py news_alert')
    exit(-1)

# the first command line argument is the news alert data.
# Use the given code to encode the data into bytes:
org_alert = sys.argv[1].encode()

# Read the public key from the file into a variable
# using the PUB_PEMK Environment Variable as the filename.
pub_pem = os.environ.get('PUB_PEMK')
with open(pub_pem,'rb') as public_key_file:
    public_key = serialization.load_pem_public_key(
        public_key_file.read()
    )

encrypted = public_key.encrypt(
    org_alert,
    padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None
    )
)



# encrypt the data



# Read the private key from the file into a variable
# using the PEMK Environment Variable as the filename.

# replace the following line of code and decrypt 
# the encrypted alert using the private key and assign 
# the decrpted data to the variable decrypted.
priv_pem = os.environ.get('PEMK')
with open(priv_pem,'rb') as private_key_file:
    private_key = serialization.load_pem_private_key(
        private_key_file.read(),
        password=None
        
    )
decrypted = private_key.decrypt(
    encrypted,
    padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None
    )
)

# print the decrypted alert (given below).
print(decrypted.decode())


