from flask import Flask, render_template, request, redirect, url_for
import firebase_admin
from firebase_admin import credentials, db
import time

app = Flask(__name__)

cred = credentials.Certificate('Key.json')
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://smart-air-conditioner-63ffc-default-rtdb.firebaseio.com'
})

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/save_to_firebase_0', methods=['POST'])
def save_to_firebase_0():
    ref = db.reference('Mode')
    ref.set(0)
    return redirect(url_for('index'))
@app.route('/save_to_firebase_1', methods=['POST'])
def save_to_firebase_1():
    ref = db.reference('Mode')
    ref.set(1)
    return redirect(url_for('index'))
@app.route('/save_to_firebase_2', methods=['POST'])
def save_to_firebase_2():
    ref = db.reference('Mode')
    ref.set(2)
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
