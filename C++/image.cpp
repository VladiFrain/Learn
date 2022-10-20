#include "header.h"

using namespace std;
//пример вложенного класса(композиция)
class Image
{
public:
	//получение информации о группе пикселей
	void GetImageInfo()
	{
		for (int i = 0; i < LENGTH; i++)
		{
			cout << pixels[i].GetInfo() << endl;
		}
	}

private:
	//cоздание вложенного класса(нельзя использовать отдельно от класса Image)
	class Pixel
	{
	public:
		Pixel(int R, int G, int B)
		{
			if (R >= 0 && R < 256 && G >= 0 && G < 256 && B >= 0 && B < 256)
			{
				this->R = R;
				this->G = G;
				this->B = B;
			}
			else 
			{
				cout << "Error R or G or B are not in the range from 0 to 255" << endl;
				this->R = 0;
				this->G = 0;
				this->B = 0;
			}
		}
		//получение информации о пикселе
		string GetInfo()
		{
			return "Pixl: R = " + to_string(R) + "\tG = " + to_string(G) + "\tB = " + to_string(B);
		}

	private:
		int R;
		int G;
		int B;
	};
	//массив объектов
	static const int LENGTH = 5;
	Pixel pixels[LENGTH]
	{
		Pixel(60,4,64),
		Pixel(4,14,10),
		Pixel(111,4,24),
		Pixel(244,244,14),
		Pixel(111,179,64)
	};
	//пример динамического массива объектов
	Pixel *pix = new Pixel[1]{
		Pixel(4,44,54)
	};
};

void Images()//консольная команда: -c im
{
	Image image;
	image.GetImageInfo();
}