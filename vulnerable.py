# --- HIGH ---
user_input = "2 + 2"
result = eval(user_input)  # HIGH: ejecución remota

import pickle
data = pickle.loads(b"some untrusted bytes")  # HIGH: ejecución remota
password = "123456"  # HIGH: contraseña hardcodeada
API_KEY = "1234567890abcdef"  # HIGH: credencial hardcodeada

# --- MEDIUM ---
import hashlib
def medium_md5(password):
    hash = hashlib.md5(password.encode()).hexdigest()  # MEDIUM: hash sin sal
    print("MD5 hash:", hash)

user_input2 = "some text"
print("User input is: " + user_input2)  # MEDIUM: concatenación insegura

# --- LOW ---
def low_token():
    token = "abcdef123456"  # LOW: exposición mínima
    print("Token:", token)

data2 = {"key": "value"}
print(data2)  # LOW: exposición de datos no sensibles
