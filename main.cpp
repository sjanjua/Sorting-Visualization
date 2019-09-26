#include <SFML/Graphics.hpp>
#include "Item.h"
#include <vector>
#include <random>

bool isSorted = true;

void reset( std::vector< Item >& items )
{
	isSorted = false;

	float startPosition = 100.0f;

	std::srand( ( unsigned )time( 0 ) );

	for ( int i = 0; i < items.size(); i++ )
	{
		int value = std::rand() % 800;
		int ratio = ( float( value ) / 800.0f ) * 150;

		sf::Color color = sf::Color( ratio * 0x00ff00ff );

		items.at( i ) = Item( value, startPosition, 0.0f );

		items.at( i ).setColor( color );

		startPosition += 1.0f;
	}
}

void sort( std::vector< Item >& items, sf::RenderWindow& window )
{
	if ( isSorted == false )
	{
		for ( int i = 0; i < items.size(); i++ )
		{
			Item& item1 = items.at( i );
			sf::Vector2f item1Position = item1.getPosition();

			for ( int j = 1; j < items.size(); j++ )
			{
				Item& item2 = items.at( j );
				sf::Vector2f item2Position = item2.getPosition();

				if ( item1.getValue() > item2.getValue() )
				{
					Item temp = Item( item1 );
					items.at( i ) = Item( item2 );
					items.at( i ).setPosition( item1Position.x, item1Position.y );

					items.at( j ) = Item( temp );
					items.at( j ).setPosition( item2Position.x, item2Position.y );
				}
			}

			window.clear();
			for ( int k = 0; k < items.size(); k++ )
			{
				window.draw( items.at( k ) );
			}
			window.display();

		}

		isSorted = true;
	}

	/*window.clear();
	for ( int k = 0; k < items.size(); k++ )
	{
		window.draw( items.at( k ) );
	}
	window.display();*/
	
}

int main()
{
	sf::RenderWindow window( sf::VideoMode( 1600, 800 ), "Sorting Visualization" );

	sf::Event ev;

	std::vector< Item > items( 1000 );

	reset( items );

	while ( window.isOpen() )
	{
		while ( window.pollEvent( ev ) )
		{
			if ( ev.type == sf::Event::Closed )
			{
				window.close();
			}

			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
			{
				window.close();
			}

			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::R ) )
			{
				reset( items );
			}
		}

		//window.clear();

		if ( isSorted == false )
		{
			sort( items, window );
		}

		//window.display();
	}

	return 0;
}