import base64

encoded_text = "9B2H.UEY<Og&.u&c@bH)htr7Sp(rBub.^xMN{O:bFTNt4z^\"[I?V2Fy0}}wLHTJ85rbg@iLPg%R;&3W@CZC"

try:
    decoded_bytes = base64.b64decode(encoded_text)
    decoded_text = decoded_bytes.decode('utf-8')
    print(decoded_text)
except Exception as e:
    print(f"Decoding error: {e}")
