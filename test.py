import json
from minero import proof_of_work

example_block =  "{\
     \"index\": 1,\
     \"transactions\": [\
       {\
         \"from\": \"string\",\
         \"to\": \"string\",\
         \"type\": \"string\",\
         \"content\": \"value\",\
         \"timestamp\": 1582301090.8854582,\
         \"tx_previous_hash\": \"99ae4e4b32f8b29fba5277e30180f3d75436b9756d1ec075f5aa5519aa15c9c0\",\
         \"tx_nonce\": 183\
       },\
       {\
         \"from\": \"string\",\
         \"to\": \"string\",\
         \"type\": \"string\",\
         \"content\": \"qqvalue\",\
         \"timestamp\": 1582301834.1500485,\
         \"tx_previous_hash\": \"9cfd783ddabdb228bd70357446c49ed2b2d98df0cf5d315f4eb69eb5d3148f40\",\
         \"tx_nonce\": 20\
       }\
     ],\
     \"timestamp\": 1582301860.202116,\
     \"nonce\":0,\
     \"previous_hash\": \"19de66af7e186f2eeba3598e625548366237b7a99389de89f06a641ecf319e7e\"\
}"

print(">> Bloc: ", json.loads(example_block))

print(">> proof_of_work: ", proof_of_work(example_block, "nonce", 10, True))