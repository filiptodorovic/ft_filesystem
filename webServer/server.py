from flask import Flask, jsonify

app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'

@app.route('/api/fuse/get')
def fuse_get():
    response = {'status': 'success', 'message': 'Hello there'}
    return jsonify(response)

@app.route('/api/fuse/open', methods=['POST'])
def post_example():
    # Get the JSON data from the POST request
    data = request.get_json()

    if 'message' in data:
        received_message = data['message']
        response = {'status': 'success', 'message_received': received_message}
    else:
        response = {'status': 'error', 'message': 'Message not found in the request'}

    return jsonify(response)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080)
