#include <iostream>
#include <vector>

using namespace std;

bool match(vector < string > frag, string file)
{
	while (frag.size() > 0)
	{
		size_t head = file.find(frag[0]);
		size_t tail = file.find(frag[0], file.length() - frag[0].length());
		if (head == string::npos && tail == string::npos)
			return false;

		string head_target, tail_target;
		if (head == 0 && tail == string::npos)
		{
			head_target = "";
			tail_target = file.substr(frag[0].length());
		}
		else if (head == string::npos && tail == (file.length() - frag[0].length()))
		{
			head_target = file.substr(0, tail);
			tail_target = "";
		}
		else
		{
			head_target = file.substr(0, tail);
			tail_target = file.substr(frag[0].length());
		}

		frag.erase(frag.begin());

		bool found = false;
		for (int i = 0; i < frag.size(); i++)
		{
			if (head_target == frag[i])
				found = true;
			if (tail_target == frag[i])
				found = true;
			if (found)
			{
				frag.erase(frag.begin() + i);
				break;
			}
		}

		if (!found)
			return false;
	}

	return true;
}

void recover_file(vector < string > &frag)
{
	int file_length = 0;
	for (int i = 0; i < frag.size(); i++)
		file_length += frag[i].length();
	file_length <<= 1;
	file_length /= frag.size();

	string head = frag[0];
	vector < string > tail;

	for (int i = 1; i < frag.size(); i++)
		if (frag[i].length() == (file_length - head.length()) && frag[i] != head)
		{
			bool add = true;
			for (int j = 0; j < tail.size(); j++)
				if (frag[i] == tail[j])
				{
					add = false;
					break;
				}
			if (add)
				tail.push_back(frag[i]);
		}

	if (tail.size() == 0)
	{
		cout << (head + head) << endl;
		return;
	}
	for (int i = 0; i < tail.size(); i++)
	{
		string file = head + tail[i];
		if (match(frag, file))
		{
			cout << file << endl;
			return;
		}
		file = tail[i] + head;
		if (match(frag, file))
		{
			cout << file << endl;
			return;
		}
	}
}

int main(int ac, char *av[])
{
	int cases;
	vector < string > frag;
	string line;

	cin >> cases;
	cin.ignore();
	getline(cin, line);

	while ((cases--) > 0)
	{
		frag.clear();
		while (getline(cin, line), line.length() > 0)
			frag.push_back(line);

		if (frag.size() == 2)
			cout << (frag[0] + frag[1]) << endl;
		else
			recover_file(frag);

		if (cases > 0)
			cout << endl;
	}

	return 0;
}
