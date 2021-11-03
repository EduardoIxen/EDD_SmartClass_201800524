import json


def loadNotes(notes_text, hash_table):
    notes = json.loads(notes_text)
    for usuario in notes["usuarios"]:
        print(usuario)
    return {"message": "NOtas cargadas con exito."},200
