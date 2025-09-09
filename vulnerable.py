# archivo: vulnerable.py
def test_vulnerability():
    password = "123456"  # Horusec debería detectarlo como vulnerabilidad
    print(f"Contraseña: {password}")


API_KEY = "1234567890abcdef" 




user_input = "2 + 2"
result = eval(user_input)  # Riesgo de ejecución remota de código



import pickle
data = pickle.loads(b"some untrusted bytes")  # Puede ejecutar código malicioso


