import pytest
from src.app import first, second, dbtest

@pytest.mark.test1
def test_all():
    assert first(10,20) == 30,"Oh Thats hot!"
    assert second(3) == [0,3,6],"thats hot"

@pytest.mark.test2
def testdb():
    tz = dbtest()
    fill = {
        "username": "That's hot",
        "password": "ahahah"
    }
    bypass_validation = False
    result = tz.insert_one(fill, bypass_validation)
    assert result.acknowledged == True, "Thats hot!"