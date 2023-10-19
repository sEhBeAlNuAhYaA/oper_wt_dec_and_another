#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//format editing
vector <int> convert(string* input) {
	vector <int> in;
	for (auto el : *input) {
		in.push_back(atoi(&el));
	}
	return in;
}
vector <char> convert_char(string* input) {
	vector <char> in;
	for (auto el : *input) {
		in.push_back(el);
	}
	return in;
}
vector <int> From_SHchar_to_int(vector <char> input) {
	vector <int> CEL;
	for (int i = 0; i < input.size(); i++) {
		switch (input[i]) {
		case 'A':
			CEL.push_back(10);
			continue;
			break;
		case 'B':
			CEL.push_back(11);
			continue;
			break;
		case 'C':
			CEL.push_back(12);
			continue;
			break;
		case 'D':
			CEL.push_back(13);
			continue;
			break;
		case 'E':
			CEL.push_back(14);
			continue;
			break;
		case 'F':
			CEL.push_back(15);
			continue;
			break;
		}
		CEL.push_back(input[i] - '0');

	}

	return CEL;
}
vector <int> reform(vector<int> input) {
	vector <int> answer;
	for (int i = input.size() - 1; i >= 0; i--) {
		answer.push_back(input[i]);
	}
	return answer;
}
//...to...
vector <int> des_to_DV(int number, int SS) {
	vector <int> i;
	int	dop = number;
	while (dop >= SS) {
		i.push_back(dop % SS);
		dop = dop / SS;
	}
	i.push_back(dop);
	i = reform(i);
	return i;
}
vector <char> des_to_SH(int number) {
	vector <int> i;
	int	dop = number;
	while (dop >= 16) {
		i.push_back(dop % 16);
		dop = dop / 16;
	}
	i.push_back(dop);

	i = reform(i);
	vector <char> answer;
	for (auto el : i) {
		if (el > 9) {
			answer.push_back(static_cast<char>(el + 55));
		}
		else {
			answer.push_back(el + 48);
		}

	}
	return answer;
}
vector <int> Drob_to_DV(double DROB, int SS) {
	vector <int> answer;
	int counter = 0;
	int floo = 0;
	while (counter < 4 || DROB > 0) {
		DROB = (DROB - floo) * SS;
		if (DROB == 0) {
			break;
		}
		floo = floor(DROB);

		answer.push_back(floo);
		counter++;
	}
	return answer;
}
vector <char> Drob_to_SH(double DROB) {
	vector <char> answer;
	int counter = 0;
	int floo = 0;
	while (counter < 4 || DROB > 0) {
		DROB = (DROB - floo) * 16;
		if (DROB == 0) {
			break;
		}
		floo = floor(DROB);
		if (floo > 9) {
			answer.push_back(static_cast<char>(floo + 55));
		}
		else {
			answer.push_back(floo + 48);
		}
		counter++;
	}
	return answer;
}
void des_float_to_DVSH(float number, int SS) {
	double DROB = number - floor(number);
	number = number - DROB;


	if (SS == 16) {
		vector <char> CELCH;
		vector <char> DROBCH;
		CELCH = des_to_SH(number);
		DROBCH = Drob_to_SH(DROB);
		for (auto el : CELCH) {
			cout << el;
		}
		cout << '.';

		for (auto el : DROBCH) {
			cout << el;
		}
	}
	else {
		vector <int> CELCH;
		vector <int> DROBCH;
		CELCH = des_to_DV(number, SS);
		DROBCH = Drob_to_DV(DROB, SS);

		for (auto el : CELCH) {
			cout << el;
		}
		cout << '.';

		for (auto el : DROBCH) {
			cout << el;
		}
	}

}
// ...to dec
double v_des_drob(string input, int SS) {
	int dot_position = 0;
	for (int i = 0; i < size(input); i++) {
		if (input[i] == '.') {
			dot_position = i;
		}
	}

	vector <int> CEL;
	vector <int> DROB;

	for (int i = 0; i < dot_position; i++) {
		switch (input[i]) {
		case 'A':
			CEL.push_back(10);
			continue;
			break;
		case 'B':
			CEL.push_back(11);
			continue;
			break;
		case 'C':
			CEL.push_back(12);
			continue;
			break;
		case 'D':
			CEL.push_back(13);
			continue;
			break;
		case 'E':
			CEL.push_back(14);
			continue;
			break;
		case 'F':
			CEL.push_back(15);
			continue;
			break;
		}
		CEL.push_back(input[i] - '0');

	}
	for (int i = dot_position; i < size(input) + 1; i++) {
		switch (input[i]) {
		case 'A':
			CEL.push_back(10);
			continue;
			break;
		case 'B':
			CEL.push_back(11);
			continue;
			break;
		case 'C':
			CEL.push_back(12);
			continue;
			break;
		case 'D':
			CEL.push_back(13);
			continue;
			break;
		case 'E':
			CEL.push_back(14);
			continue;
			break;
		case 'F':
			CEL.push_back(15);
			continue;
			break;
		}
		DROB.push_back(input[i] - '0');
	}

	double answer_CEL = 0;
	int starting_index = CEL.size() - 1;
	for (int i = 0; i < CEL.size(); i++) {
		answer_CEL = answer_CEL + (CEL[i] * pow(SS, starting_index));
		starting_index--;
	}

	double answer_DROB = 0;
	starting_index = -1;
	for (int i = 1; i < DROB.size() - 1; i++) {

		answer_DROB = answer_DROB + (DROB[i] * pow(SS, starting_index));
		starting_index--;
	}
	double answer = answer_CEL + answer_DROB;
	return answer;

}
int v_des_cel(string input, int SS) {
	int answer = 0;


	vector <int> array_number;
	for (int i = 0; i < size(input); i++) {
		switch (input[i]) {
		case 'A':
			array_number.push_back(10);
			continue;
			break;
		case 'B':
			array_number.push_back(11);
			continue;
			break;
		case 'C':
			array_number.push_back(12);
			continue;
			break;
		case 'D':
			array_number.push_back(13);
			continue;
			break;
		case 'E':
			array_number.push_back(14);
			continue;
			break;
		case 'F':
			array_number.push_back(15);
			continue;
			break;
		}
		array_number.push_back(input[i] - '0');
	}

	int starting_index = array_number.size() - 1;
	for (int i = 0; i < array_number.size(); i++) {
		answer = answer + (array_number[i] * pow(SS, starting_index));
		starting_index--;
	}
	return answer;

}
// adding (8 and 2)(drob)
vector <int> add_cel(vector <int> first_num, vector <int> second_num, int SS) {
	vector <int> answer;
	int biggest = 0;
	int smallest = 0;
	vector <int> con_smaller_num;
	vector <int> perehod;

	vector <int> onother;
	if (first_num.size() >= second_num.size()) {
		biggest = first_num.size() - 1;
		smallest = second_num.size() - 1;
		perehod = second_num;
		onother = first_num;
	}
	else {
		biggest = second_num.size() - 1;
		smallest = first_num.size() - 1;
		perehod = first_num;
		onother = second_num;
	}
	int def = biggest - smallest;
	while (def != 0) {
		con_smaller_num.push_back(0);
		def--;
	}
	for (auto el : perehod) {
		con_smaller_num.push_back(el);

	}
	int perenos = 0;
	for (int i = biggest; i > -1; i--) {
		int new_num = onother[i] + con_smaller_num[i] + perenos;
		//  cout << "new_num: " << new_num  << "perenos: " << perenos << endl;

		if (new_num >= SS) {
			if (new_num == SS) {
				perenos = 1;
				answer.push_back(0);
			}
			else {
				answer.push_back(new_num % SS);
				perenos = new_num / SS;
			}
			//	cout << "new_num: " << new_num << " perenos: " << perenos << " first: " << first_num[i] << " second: " << con_smaller_num[i] << endl;

		}
		else {
			answer.push_back(new_num);
			//	cout << "new_num: " << new_num << " perenos: " << perenos << " first: " << first_num[i] << " second: " << con_smaller_num[i] << endl;
			perenos = 0;
		}
		//cout << "new_num: " << new_num << " perenos: " << perenos << " first: " << onother[i] << " second: " << con_smaller_num[i] << " answer:" <<answer[answer.size()-1] << endl;
		if (i == 0 && perenos != 0) {
			while (perenos != 0) {
				if (perenos >= SS) {
					answer.push_back(perenos / SS);
				}
				answer.push_back(perenos);
				perenos = perenos / SS;
			}
		}
	}
	answer = reform(answer);

	return answer;

}
vector <int> dot_deleting(vector <char> input) {
	vector <int> full_number;
	for (char el : input) {
		if (el == '.') {
			continue;
		}
		switch (el) {
		case 'A':
			full_number.push_back(10);
			continue;
			break;
		case 'B':
			full_number.push_back(11);
			continue;
			break;
		case 'C':
			full_number.push_back(12);
			continue;
			break;
		case 'D':
			full_number.push_back(13);
			continue;
			break;
		case 'E':
			full_number.push_back(14);
			continue;
			break;
		case 'F':
			full_number.push_back(15);
			continue;
			break;
		}
		full_number.push_back(el - 48);
	}

	return full_number;
}
vector <char> add_drob(vector <char> first, vector <char> second, int SS) {
	vector <int> full_number_first;
	vector <int> full_number_second;
	//cout << size(first) << endl;
	int dot_position_first = 0;
	for (int i = first.size() - 1; i > 0; i--) {
		if (first[i] == '.') {
			break;
		}
		//cout << "dot_position -> " << dot_position << endl;
		dot_position_first++;
	}
	int dot_position_second = 0;
	for (int i = second.size() - 1; i > 0; i--) {
		if (second[i] == '.') {
			break;
		}
		//cout << "dot_position -> " << dot_position << endl;
		dot_position_second++;
	}


	full_number_first = dot_deleting(first);
	full_number_second = dot_deleting(second);

	if (dot_position_first > dot_position_second) {
		int def = dot_position_first - dot_position_second;
		while (def > 0) {
			full_number_second.push_back(0);
			def--;
		}
	}
	else {
		int def = dot_position_second - dot_position_first;
		while (def > 0) {
			full_number_first.push_back(0);
			def--;
		}
	}

	vector <int> answer_int = add_cel(full_number_first, full_number_second, SS);
	vector <char> answer_char;
	for (int i = 0; i < answer_int.size(); i++) {
		if (answer_int.size() - i == dot_position_first) {
			answer_char.push_back('.');
		}
		answer_char.push_back(answer_int[i] + 48);
	}
	return answer_char;

}
//subtraction
vector <int> sub_cel(vector <int> first_num, vector <int> second_num, int SS) {
	vector <int> answer;
	int biggest = 0;
	int smallest = 0;
	vector <int> con_smaller_num;
	vector <int> perehod;
	bool isneg = false;
	vector <int> onother;
	if (first_num.size() >= second_num.size()) {
		biggest = first_num.size() - 1;
		smallest = second_num.size() - 1;
		perehod = second_num;
		onother = first_num;
	}
	else {
		biggest = second_num.size() - 1;
		smallest = first_num.size() - 1;
		perehod = first_num;
		onother = second_num;
		isneg = true;
	}
	int def = biggest - smallest;
	while (def != 0) {
		con_smaller_num.push_back(0);
		def--;
	}
	for (auto el : perehod) {
		con_smaller_num.push_back(el);

	}
	int zaim = 0;
	for (int i = biggest; i > -1; i--) {
		int new_num = onother[i] - con_smaller_num[i] - zaim;
		if (new_num < 0) {
			zaim = 1;
			answer.push_back(new_num + SS);
		}
		else {
			answer.push_back(new_num);
			zaim = 0;
		}
		//	cout << "new_num: " << new_num << " zaim: " << zaim << " first: " << onother[i] << " second: " << con_smaller_num[i] << endl;

	}
	answer = reform(answer);
	if (isneg) {
		cout << "-";
	}
	for (auto el : answer) {
		cout << el;
	}
	cout << endl;
	return answer;

}
vector <char> zapoln(int dot_dif, vector<char> input) {
	while (dot_dif > 0) {
		input.push_back('0');
		dot_dif--;
	}
	return input;
}
vector <char> sub_drob(vector <char> first, vector <char> second, int SS) {

	int dot_pos_first = 0;
	int dot_pos_second = 0;
	for (int i = first.size() - 1; i > 0; i--) {
		if (first[i] == '.') {
			break;
		}
		dot_pos_first++;
	}
	for (int i = second.size() - 1; i > 0; i--) {
		if (second[i] == '.') {
			break;
		}
		dot_pos_second++;
	}
	int dot_dif;
	if (dot_pos_first > dot_pos_second) {
		dot_dif = dot_pos_first - dot_pos_second;
		second = zapoln(dot_dif, second);
	}
	else {
		dot_dif = dot_pos_second - dot_pos_first;
		first = zapoln(dot_dif, first);
	}
	vector <int> full_number_first;
	vector <int> full_number_second;
	//cout << size(first) << endl;
	int dot_position = 0;
	for (int i = first.size() - 1; i > 0; i--) {
		if (first[i] == '.') {
			break;
		}
		dot_position++;
	}

	full_number_first = dot_deleting(first);
	full_number_second = dot_deleting(second);

	vector <int> answer_int = sub_cel(full_number_first, full_number_second, SS);

	vector <char> answer_char;
	for (int i = 0; i < answer_int.size(); i++) {
		if (answer_int.size() - i == dot_position) {
			answer_char.push_back('.');
		}
		switch (answer_int[i]) {
		case 10:
			answer_char.push_back(answer_int[i] + 55);
			continue;
			break;
		case 11:
			answer_char.push_back(answer_int[i] + 55);
			continue;
			break;
		case 12:
			answer_char.push_back(answer_int[i] + 55);
			continue;
			break;
		case 13:
			answer_char.push_back(answer_int[i] + 55);
			continue;
			break;
		case 14:
			answer_char.push_back(answer_int[i] + 55);
			continue;
			break;
		case 15:
			answer_char.push_back(answer_int[i] + 55);
			continue;
			break;
		}
		answer_char.push_back(answer_int[i] + 48);
	}
	for (auto el : answer_char) {
		cout << el;
	}
	return answer_char;
}
//multik
vector <int> multik_null_adding(vector<int>input, int dot_otdel) {
	vector <int> answer;
	for (int i = input.size() - 1; i >= 0; i--) {
		if (i == input.size() - 1) {
			for (int j = dot_otdel; j > 1; j--) {
				answer.push_back(0);
			}
		}

		answer.push_back(input[i]);

	}
	answer = reform(answer);
	return answer;
}
vector <int> multik_adding(vector <int> input1, vector <int> input2, int dot_otdel, int SS) {
	vector <int> input_1_con = input1;
	vector <int> input_2_con = multik_null_adding(input2, dot_otdel);

	vector <int> answer = add_cel(input_1_con, input_2_con, SS);
	return answer;
}
vector <int> multik(vector <int> first, vector <int> second, int SS) {
	int biggest = 0;
	int smallest = 0;
	int def = 0;
	vector <int> small_null;
	vector <int> perehod;
	vector <int> onother;
	if (first.size() > second.size()) {
		biggest = first.size() - 1;
		smallest = second.size() - 1;
		perehod = second;
		onother = first;
		def = biggest - smallest;
	}
	else {
		biggest = second.size() - 1;
		smallest = first.size() - 1;
		perehod = first;
		onother = second;
		def = biggest - smallest;
	}
	while (def > 0) {
		small_null.push_back(0);
		def--;
	}
	for (auto el : perehod) {
		small_null.push_back(el);
	}
	vector <int> promezh_1 = { 0 };
	vector <int> promezh_2;
	int dot_otdel = 0;
	int perenos = 0;
	for (int i = biggest; i > -1; i--) {
		for (int j = biggest; j > -1; j--) {
			int new_num = (onother[j] * small_null[i]) + perenos;
			//  cout << "new_num: " << new_num  << "perenos: " << perenos << endl;

			if (new_num >= SS) {

				if (new_num == SS) {
					perenos = 1;
					promezh_2.push_back(0);
				}
				else {
					promezh_2.push_back(new_num % SS);
					perenos = new_num / SS;
				}
				//	cout << "new_num: " << new_num << " perenos: " << perenos << " first: " << first_num[i] << " second: " << con_smaller_num[i] << endl;

			}
			else {
				promezh_2.push_back(new_num);
				//	cout << "new_num: " << new_num << " perenos: " << perenos << " first: " << first_num[i] << " second: " << con_smaller_num[i] << endl;
				perenos = 0;
			}
			//cout << "new_num: " << new_num << " perenos: " << perenos << " first: " << onother[i] << " second: " << small_null[i] << " j: " << j << " answer:" << promezh_2[biggest - j] << endl;
			if (j == 0 && perenos != 0) {
				while (perenos != 0) {
					if (perenos >= SS) {
						promezh_2.push_back(perenos / SS);
					}
					promezh_2.push_back(perenos);
					perenos = perenos / SS;
				}
			}
		}
		promezh_2 = reform(promezh_2);
		promezh_1 = multik_adding(promezh_1, promezh_2, dot_otdel, SS);
		//cout << endl << "Promezh_1: ";
		/*
		for (auto el : promezh_1) {
			cout << el;
		}
		cout << endl << "Promezh_2: ";
		for (auto el : promezh_2) {
			cout << el;
		}
		*/
		promezh_2 = { 0 };
		dot_otdel++;


	}
	vector <int> answer;
	int count = 0;
	for (auto el : promezh_1) {
		if (el == 0) {
			count++;
		}
		break;
	}
	for (int i = count; i < promezh_1.size(); i++) {
		answer.push_back(promezh_1[i]);
	}

	cout << endl;
	for (auto el : answer) {
		cout << el;
	}
	cout << endl;
	return answer;
}
vector <int> multik_drob(vector<char> first, vector <char> second, int SS) {
	vector <int> f_int;
	vector <int> s_int;
	int dot_pos = 0;
	for (int i = first.size() - 1; i > 0; i--) {
		if (first[i] == '.') {
			break;
		}
		dot_pos++;
	}
	for (int i = second.size() - 1; i > 0; i--) {
		if (second[i] == '.') {
			break;
		}
		dot_pos++;
	}
	f_int = dot_deleting(first);
	s_int = dot_deleting(second);

	vector <int> answer;
	answer = multik(f_int, s_int, SS);
	vector <char> answer_char;

	for (int i = 0; i <= answer.size() - 1; i++) {
		if (i == answer.size() - dot_pos) {
			answer_char.push_back('.');
		}
		switch (answer[i]) {
		case 10:
			answer_char.push_back(answer[i] + 55);
			continue;
			break;
		case 11:
			answer_char.push_back(answer[i] + 55);
			continue;
			break;
		case 12:
			answer_char.push_back(answer[i] + 55);
			continue;
			break;
		case 13:
			answer_char.push_back(answer[i] + 55);
			continue;
			break;
		case 14:
			answer_char.push_back(answer[i] + 55);
			continue;
			break;
		case 15:
			answer_char.push_back(answer[i] + 55);
			continue;
			break;
		}
		answer_char.push_back(answer[i] + 48);
	}

	
	cout << "Answer: ";
	for (auto el : answer_char) {
		cout << el;
	}
	cout << endl;
	return answer;
}
//main
int main() {
	cout << "╔══╗╔══╗╔════╗╔══╗╔══╗╔══╗   ╔╗──╔══╗╔══╗─╔══╗─╔╗" << endl;
	cout << "║╔╗║║╔═╝╚═╗╔═╝╚╗╔╝║╔╗║║╔═╝   ║║──║╔╗║║╔╗║─║╔╗║╔╝║" << endl;
	cout << "║╚╝║║║────║║───║║─║║║║║╚═╗   ║║──║╚╝║║╚╝╚╗║╚╝║╚╗║" << endl;
	cout << "║╔╗║║║────║║───║║─║║║║╚═╗║   ║║──║╔╗║║╔═╗║║╔╗║─║║" << endl;
	cout << "║║║║║╚═╗──║║──╔╝╚╗║╚╝║╔═╝║   ║╚═╗║║║║║╚═╝║║║║║─║║" << endl;
	cout << "╚╝╚╝╚══╝──╚╝──╚══╝╚══╝╚══╝   ╚══╝╚╝╚╝╚═══╝╚╝╚╝─╚╝" << endl;
	bool isTrue = true;
	while (isTrue) {
		cout << "1. From decimal to binary; (int & float);" << endl;
		cout << "2. From -//- to decimal (int & float);" << endl;
		cout << "3. Addition (binary & octuple)(int & float);" << endl;
		cout << "4. Subtraction (int(binary & octuple) & float);" << endl;
		cout << "5. Multiplication (int & float);" << endl;
		cout << "   ENTER your choice: ";
		int answer;
		cin >> answer;
		cout << "<================================================>" << endl;
		vector <int> input_con;
		vector <char> i;
		int perevod = 0;
		string in;
		vector <int> answer_vector;
		vector <char> answer_char;
		string task31;
		string task32;
		int sys = 0;

		switch (answer) {
		case 1:
			float input;
			cout << "Converting from decimal;" << endl;
			cout << "Enter the Number: ";
			cin >> input;


			input_con = des_to_DV(input, 2);
			cout << "DV: ";
			for (auto el : input_con) {
				cout << el;
			}
			cout << endl;

			cout << "VM: ";
			input_con = des_to_DV(input, 8);
			for (auto el : input_con) {
				cout << el;
			}
			cout << endl;

			cout << "SH: ";

			i = des_to_SH(input);
			for (auto el : i) {
				cout << el;
			}
			cout << endl;

			cout << "Enter the Number: ";
			cin >> input;
			cout << "DV: ";
			des_float_to_DVSH(input, 2);
			cout << endl;
			cout << "VM: ";
			des_float_to_DVSH(input, 8);
			cout << endl;
			cout << "SH: ";
			des_float_to_DVSH(input, 16);

			break;

		case 2:
			cout << "Converting to decimal (int)" << endl;
			cout << "Enter the Number (binary): ";
			cin >> in;
			cout << "To decimal from binary (int): " << v_des_cel(in, 2) << endl;
			cout << "Enter the Number (octuple): ";
			cin >> in;
			cout << "To decimal from binary (octuple): " << v_des_cel(in, 8) << endl;
			cout << "Enter the Number (hexadecimal): ";
			cin >> in;
			cout << "To decimal from binary (hexadecimal): " << v_des_cel(in, 16) << endl;

			cout << endl << "Converting to decimal (float)" << endl;
			cout << "Enter the Number (binary): ";
			cin >> in;
			cout << "To decimal from binary (int): " << v_des_drob(in, 2) << endl;
			cout << "Enter the Number (octuple): ";
			cin >> in;
			cout << "To decimal from binary (octuple): " << v_des_drob(in, 8) << endl;
			cout << "Enter the Number (hexadecimal): ";
			cin >> in;
			cout << "To decimal from binary (hexadecimal): " << v_des_drob(in, 16) << endl;
			break;
		case 3:
			cout << "Addition (int);" << endl;
			cout << "Enter the Numbers (binary): " << endl << "1. ";
			cin >> task31;
			cout << "2. ";
			cin >> task32;
			answer_vector = add_cel(convert(&task31), convert(&task32), 2);
			cout << "Answer (binary): ";
			for (auto el : answer_vector) {
				cout << el;
			}
			cout << endl;
			cout << "Enter the Numbers (octuple): " << endl << "1. ";
			cin >> task31;
			cout << "2. ";
			cin >> task32;
			answer_vector = add_cel(convert(&task31), convert(&task32), 8);
			cout << "Answer (octuple): ";
			for (auto el : answer_vector) {
				cout << el;
			}
			cout << endl << endl;
			cout << "Addition (float);" << endl;
			cout << "Enter the Numbers (binary): " << endl << "1. ";
			cin >> task31;
			cout << "2. ";
			cin >> task32;
			answer_char = add_drob(convert_char(&task31), convert_char(&task32), 2);
			cout << "Answer (binary): ";
			for (auto el : answer_char) {
				cout << el;
			}
			cout << endl;
			cout << "Enter the Numbers (octuple): " << endl << "1. ";
			cin >> task31;
			cout << "2. ";
			cin >> task32;
			answer_char = add_drob(convert_char(&task31), convert_char(&task32), 8);
			cout << "Answer (octuple): ";
			for (auto el : answer_char) {
				cout << el;
			}
			cout << endl;

			break;
		case 4:
			cout << "Subtraction;" << endl;
			cout << "Enter the system for operation: " << endl;
			cin >> sys;
			cout << "Enter the Numbers: " << endl << "1. ";
			cin >> task31;
			cout << "2. ";
			cin >> task32;
			cout << "Answer (int): ";
			sub_cel(convert(&task31), convert(&task32), sys);
			cout << "Enter the system for operation: " << endl;
			cin >> sys;
			cout << "Enter the Numbers: " << endl << "1. ";
			cin >> task31;
			cout << "2. ";
			cin >> task32;
			cout << "Answer (float): ";
			sub_drob(convert_char(&task31), convert_char(&task32), sys);
			break;
		case 5:
			cout << "Multiplication;" << endl;
			cout << "Enter the system for operation: " << endl;
			cin >> sys;
			cout << "Enter the Numbers: " << endl << "1. ";
			cin >> task31;
			cout << "2. ";
			cin >> task32;
			multik(From_SHchar_to_int(convert_char(&task31)), From_SHchar_to_int(convert_char(&task32)), sys);
			cout << endl;
			cout << "Enter the system for operation: " << endl;
			cin >> sys;
			cout << "Enter the Numbers: " << endl << "1. ";
			cin >> task31;
			cout << "2. ";
			cin >> task32;
			multik_drob(convert_char(&task31), convert_char(&task32), sys);
			break;

		}
		cout << endl << "<================================================>" << endl;
	}

	return 0;
}

