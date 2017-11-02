#include "Car.hpp"
namespace bEngine{
    Car::Car(GameDataRef data, float speed, float rSpeed, std::string texName, KeySet keys, std::string tag, std::string name)
    {
        _speed = speed;
        _rSpeed = rSpeed;
        if(texName != "")
            setTexture(data->assets.GetTexture(texName));
        else
            setTexture(data->assets.GetTexture("No Load"));
        _keys = keys;
        SetTag(tag);

        data->assets.LoadTexture("None Sprite", NONE_SPRITE);

        sf::Sprite fCollider;
        fCollider.setTexture(data->assets.GetTexture("None Sprite"));
        fCollider.setScale(5,36);
        fCollider.setOrigin(fCollider.getLocalBounds().width * -5.5, fCollider.getLocalBounds().height / 2);
        fCollider.setPosition(fCollider.getGlobalBounds().width / 2, fCollider.getGlobalBounds().height / 2);
        std::cout << fCollider.getGlobalBounds().width << " : " << fCollider.getGlobalBounds().height << std::endl;
        fCollider.setColor(sf::Color(0,0,0,0));
        addAttachable("Front Collider", fCollider);

        sf::Sprite bCollider;
        bCollider.setTexture(data->assets.GetTexture("None Sprite"));
        bCollider.setScale(5,36);
        bCollider.setOrigin(bCollider.getLocalBounds().width * 6.5, bCollider.getLocalBounds().height / 2);
        bCollider.setPosition(bCollider.getGlobalBounds().width / 4, bCollider.getGlobalBounds().height / 2);
        bCollider.setColor(sf::Color(0,0,0,0));
        addAttachable("Back Collider", bCollider);
    }

    void Car::Input(float dt, GameDataRef data)
    {
        if(sf::Keyboard::isKeyPressed(_keys.leftKey) && !sf::Keyboard::isKeyPressed(_keys.rightKey))
        {
            rotate(-getRotationSpeed()/* * dt*/);
            getAttached("Front Collider").rotate(-getRotationSpeed());
            getAttached("Back Collider").rotate(-getRotationSpeed());
            _aUpdating = false;
        }
        if(!sf::Keyboard::isKeyPressed(_keys.leftKey) && sf::Keyboard::isKeyPressed(_keys.rightKey))
        {
            rotate(getRotationSpeed()/* * dt*/);
            getAttached("Front Collider").rotate(getRotationSpeed());
            getAttached("Back Collider").rotate(getRotationSpeed());
            _aUpdating = false;
        }
        else if(!sf::Keyboard::isKeyPressed(_keys.leftKey) && !sf::Keyboard::isKeyPressed(_keys.rightKey))
        {
            _angle = getRotation();
            _aUpdating = true;
        }
    }

    void Car::Update(float dt, GameDataRef data)
    {
        if(_aUpdating)
        {
            _angle += (getRotation() - _angle) * (_aUpdatingTime / 60.0f);
        }
        if(getBounce() < 1)
            setBounce(getBounce() + _bounceDegeneration);
        if(getPosition().x > SCREEN_WIDTH)
        {
            if(getBounce() >= 1)
                setBounce(_bounceStrength);
            else
                setBounce(1);
            //_car.setPosition(0, _car.getPosition().y);
        }
        else if(getPosition().x < 0)
        {
            if(getBounce() >= 1)
                setBounce(_bounceStrength);
            else
                setBounce(1);
            //_car.setPosition(0, _car.getPosition().y);
        }
        if(getPosition().y > SCREEN_HEIGHT)
        {
            if(getBounce() >= 1)
                setBounce(_bounceStrength);
            else
                setBounce(1);
            //_car.setPosition(0, _car.getPosition().y);
        }
        else if(getPosition().y < 0)
        {
            if(getBounce() >= 1)
                setBounce(_bounceStrength);
            else
                setBounce(1);
            //_car.setPosition(0, _car.getPosition().y);
        }
        if(getPosition().x > SCREEN_WIDTH )
        {
            setPosition(SCREEN_WIDTH - 0.2f, getPosition().y);
            getAttached("Front Collider").setPosition(SCREEN_WIDTH - 0.2f, getPosition().y);
            getAttached("Back Collider").setPosition(SCREEN_WIDTH - 0.2f, getPosition().y);
        }
        else if(getPosition().x < 0)
        {
            setPosition(0.2f, getPosition().y);
            getAttached("Front Collider").setPosition(0.2f, getPosition().y);
            getAttached("Back Collider").setPosition(0.2f, getPosition().y);
        }
        if(getPosition().y > SCREEN_HEIGHT)
        {
            setPosition(getPosition().x, SCREEN_HEIGHT - 0.2f);
            getAttached("Front Collider").setPosition(getPosition().x, SCREEN_HEIGHT - 0.2f);
            getAttached("Back Collider").setPosition(getPosition().x, SCREEN_HEIGHT - 0.2f);
        }
        else if(getPosition().y < 0)
        {
            setPosition(getPosition().x, 0.2f);
            getAttached("Front Collider").setPosition(getPosition().x, 0.2f);
            getAttached("Back Collider").setPosition(getPosition().x, 0.2f);
        }
        if(_collisionAngle > 1)
            _collisionAngle -= _collisionAngleDegeneration;
        move(getSpeed() * std::cos((PI/180) * getAngle()) * getBounce(), getSpeed() * std::sin((PI/180) * getAngle()) * getBounce());
        getAttached("Front Collider").move(getSpeed() * std::cos((PI/180) * getAngle()) * getBounce(), getSpeed() * std::sin((PI/180) * getAngle()) * getBounce());
        getAttached("Back Collider").move(getSpeed() * std::cos((PI/180) * getAngle()) * getBounce(), getSpeed() * std::sin((PI/180) * getAngle()) * getBounce());

    }

    /*void Car::Draw(float dt, GameDataRef data)
    {
        //data->window.draw(*this);
    }*/

    float Car::getSpeed()
    {
        return _speed;
    }

    void Car::setSpeed(float speed)
    {
        _speed = speed;
    }

    float Car::getRotationSpeed()
    {
        return _rSpeed;
    }

    void Car::setRotationSpeed(float speed)
    {
        _rSpeed = speed;
    }

    float Car::getAngle()
    {
        return _angle;
    }

    void Car::setAngle(float angle)
    {
        _angle = angle;
    }

    float Car::getBounce()
    {
        return _bounce;
    }

    void Car::setBounce(float bounce)
    {
        _bounce = bounce;
    }

    KeySet Car::getKeys()
    {
        return _keys;
    }

    void Car::setKeys(sf::Keyboard::Key leftKey, sf::Keyboard::Key rightKey)
    {
        _keys.leftKey = leftKey;
        _keys.rightKey = rightKey;
    }

    void Car::setKeys(KeySet keySet)
    {
        _keys = keySet;
    }

    /*sf::RectangleShape &Car::getFrontCollider()
    {
        return _fCollider;
    }*/

    void Car::OnCollisionEnter(Object& collision, GameDataRef data)
    {
        if(collision.GetTag() == "Car")
        {
            if(BoundingBoxTest(getAttached("Front Collider"), collision))
                _bounce = _bounceStrength;
            else if(BoundingBoxTest(getAttached("Back Collider"), collision))
                _bounce = -_bounceStrength;

        }
    }

    void Car::Action1(GameDataRef data, std::string str)
    {
        setBounce(_bounceStrength);
    }
}
