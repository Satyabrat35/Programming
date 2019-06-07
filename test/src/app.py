import pymongo
import json

def first(x,y):
    z = x+y
    return z

def second(x):
    my_list = []
    for i in range(0,3):
        my_list.append(i*x)
    return my_list

def dbtest():
    with open('src/values.json') as f:
        data = json.load(f)

    cluster_uri = data["credentials"][0]["Cluster_URI"]
    client = pymongo.MongoClient(cluster_uri)
    db = client['test']
    tz = db.users
    return tz
