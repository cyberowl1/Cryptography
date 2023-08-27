from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization

# Task 1: Creation of private key
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048
)
# print(private_key)

# Task2: Serilization of private key
priv_pem = private_key.private_bytes(
    encoding= serialization.Encoding.PEM,
    format = serialization.PrivateFormat.TraditionalOpenSSL,
    encryption_algorithm=serialization.NoEncryption()
)
# print(priv_pem)
# Task: Private key is tored in file with .pem extension
# in binary mode.
with open('priv.pem','wb') as priv_pem_file:
    priv_pem_file.write(priv_pem)

# Task3: Public Key generation
public_key = private_key.public_key()

pub_pem = public_key.public_bytes(
    encoding = serialization.Encoding.PEM,
    format= serialization.PublicFormat.SubjectPublicKeyInfo,
)
with open('pub.pem','wb') as pub_pem_file:
    pub_pem_file.write(pub_pem)