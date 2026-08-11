string getAlphasOnly(int length, string WithSpaces)
{
	string Buffer = "";
	char tempCh;
	int i = 0;

	while (i < length)
	{
		tempCh = _getch();
		if ((tempCh >= 'A' && tempCh <= 'Z') || (tempCh >= 'a' && tempCh <= 'z' || tempCh == ' '))
		{
			cout << tempCh;
			Buffer.push_back(tempCh);
			i++;
		}
		else if (tempCh == '\b' && i > 0)
		{
			cout << "\b \b";
			Buffer.pop_back();
			i--;
		}
		else if (tempCh == '\r' && i > 0)
		{

			break;
		}
	}
	cout << endl;
	return Buffer;
}




title = getAlphasOnly (100 );



string getAlphasOnly(int length)
{
	string Buffer = "";
	char tempCh;
	int i = 0;

	while (i < length)
	{
		tempCh = _getch();
		if ((tempCh >= 'A' && tempCh <= 'Z') || (tempCh >= 'a' && tempCh <= 'z'))
		{
			cout << tempCh;
			Buffer.push_back(tempCh);
			i++;
		}
		else if (tempCh == '\b' && i > 0)
		{
			cout << "\b \b";
			Buffer.pop_back();
			i--;
		}
		else if (tempCh == '\r' && i > 0)
		{

			break;
		}
	}
	cout << endl;
	return Buffer;
}
