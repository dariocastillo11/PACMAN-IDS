# HIGH: 
user_input = "2 + 2"
result = eval(user_input)  # HIGH

import pickle
data = pickle.loads(b"some untrusted bytes")  # HIGH

password = "123456"  # HIGH
API_KEY = "1234567890abcdef"  # HIGH

# MEDIUM: uso de hashlib sin sal para contraseñas
import hashlib
def medium_risk(password):
    hash = hashlib.md5(password.encode()).hexdigest()  # MEDIUM
    print("MD5 hash:", hash)


def low_risk():
    token = "abcdef123456"  # LOW
    print("Token:", token)



user_input = "some text"
print("User input is: " + user_input)  # Concatenación insegura detectada como medium


data = {"key": "value"}
print(data)  # exposición de datos no sensibles, Horusec lo puede marcar como low