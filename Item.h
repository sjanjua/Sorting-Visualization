#pragma once
#include <SFML/Graphics.hpp>

class Item : public sf::Drawable
{
public:

	Item() {}
	Item( int val, float x, float y );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

	void setValue( int val )				{ _value = val; }
	void setPosition( float x, float y )	{ _position = sf::Vector2f( x, y ); _rect.setPosition( _position ); }
	void setColor( sf::Color color )		{ _color = color; _rect.setFillColor( _color ); }

	int getValue()			   { return _value; };
	sf::Vector2f getPosition() { return _position; }


	private:

		int					_value;
		sf::Color			_color;
		sf::Vector2f		_position;
		sf::RectangleShape	_rect;
};