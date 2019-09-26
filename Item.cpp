#include "Item.h"

Item::Item( int val, float x, float y )
	:	_value		( 0 ),
		_color		( sf::Color::Cyan ),
		_position	( sf::Vector2f( 0.0f, 0.0f ) ),
		_rect		( sf::Vector2f( 0.0f, 0.0f ) )
{
	setValue( val );

	_rect = sf::RectangleShape();
	_rect.setFillColor( _color );
	_rect.setSize( sf::Vector2f( 1.0f, _value ) );

	setPosition( x, y );
}

void Item::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( _rect );
}