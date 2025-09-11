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

# LOW: variable sensible expuesta
def low_risk():
    token = "abcdef123456"  # LOW
    print("Token:", token)
