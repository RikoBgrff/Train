#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;
class Product {
	size_t* myID;
	string* name;
	double* weight;
	double* price;
	double* discount;
	string* company;
public:
	static size_t ID;
	Product() :myID(nullptr), name(nullptr), weight(nullptr), price(nullptr), discount(nullptr), company(nullptr) {}
	explicit Product(const string& name, const double& weight, const double& price, const double& discount, const string& company) :Product() {
		setMyID();
		setName(name);
		setWeight(weight);
		setPrice(price);
		setDiscount(discount);
		setCompany(company);
	}
	Product(Product& other) {
		this->myID = new size_t(*other.myID);
		setName(*other.name);
		setWeight(*other.weight);
		setPrice(*other.price);
		setDiscount(*other.discount);
		setCompany(*other.company);
	}
	Product& operator=(Product& other) {
		this->myID = new size_t(*other.myID);
		setName(*other.name);
		setWeight(*other.weight);
		setPrice(*other.price);
		setDiscount(*other.discount);
		setCompany(*other.company);
		return *this;
	}
	Product(Product&& other) {
		this->myID = new size_t(*other.myID);
		delete other.myID;
		setName(*other.name);
		delete other.name;
		setWeight(*other.weight);
		delete other.weight;
		setPrice(*other.price);
		delete other.price;
		setDiscount(*other.discount);
		delete other.discount;
		setCompany(*other.company);
		delete other.company;
	}
	size_t getMyID()const {
		return *myID;
	}
	string getName()const {
		return *name;
	}
	double getWeight()const {
		return *weight;
	}
	double getPrice()const {
		return *price;
	}
	double getDiscount()const {
		return *discount;
	}
	string getCompany()const {
		return *company;
	}
	void setMyID() {
		this->myID = new size_t(ID++);
	}
	void setName(const string& name) {
		this->name = new string(name);
	}
	void setWeight(const double& weight) {
		this->weight = new double(weight);
	}
	void setPrice(const double& price) {
		this->price = new double(price);
	}
	void setDiscount(const double& discount) {
		this->discount = new double(discount);
	}
	void setCompany(const string& company) {
		this->company = new string(company);
	}
	void updateProduct() {
		int i = 0;
		cout << "1. Name " << endl;
		cout << "2. Weight" << endl;
		cout << "3. Price" << endl;
		cout << "4. Discount" << endl;
		cout << "5. Company" << endl;
		cout << "enter your selection : "; cin >> i;
		if (i == 1) {
			string* name = new string();
			cout << "Enter the new name : "; cin >> *name;
			*this->name = *name;
			delete name;
		}
		else if (i == 2) {
			double* weight = new double();
			cout << "Enter the new weight : "; cin >> *weight;
			*this->weight = *weight;
			delete weight;
		}
		else if (i == 3) {
			double* price = new double();
			cout << "Enter the new price : "; cin >> *price;
			*this->price = *price;
			delete price;
		}
		else if (i == 4) {
			double* discount = new double();
			cout << "Enter the new discount : "; cin >> *discount;
			*this->discount = *discount;
			delete discount;
		}
		else if (i == 5) {
			string* company = new string();
			cout << "Enter the new company : "; cin >> *company;
			*this->company = *company;
			delete company;
		}
	}
	explicit operator size_t() {
		return *myID;
	}
	explicit operator string() {
		return *name;
	}
	explicit operator double() {
		return *weight;
	}
	friend ostream& operator<<(ostream& out, const Product& other);
	friend istream& operator>>(istream& in, Product& other);
	~Product() {
		if (myID != nullptr) {
			delete myID;
			myID = NULL;
		}
		if (name != nullptr) {
			delete name;
			name = nullptr;
		}
		if (weight != nullptr) {
			delete weight;
			weight = nullptr;
		}
		if (price != nullptr) {
			delete price;
			price = nullptr;
		}
		if (discount != nullptr) {
			delete discount;
			discount = nullptr;
		}
		if (company != nullptr) {
			delete company;
			company = nullptr;
		}
	}
};
ostream& operator<<(ostream& out, const Product& other) {
	cout << "----------------------------------\n";
	out << "ID       : " << other.getMyID() << endl;
	out << "Name     : " << other.getName() << endl;
	out << "Weight   : " << other.getWeight() << endl;
	out << "Price    : " << other.getPrice() << endl;
	out << "Discount : " << other.getDiscount() << endl;
	out << "Company  : " << other.getCompany() << endl;
	cout << "----------------------------------\n";
	return out;
}
istream& operator>>(istream& in, Product& other) {
	other.setMyID();
	string* name = new string();
	cout << "Enter the name : "; in >> *name;
	other.setName(*name);
	delete name;
	double* weight = new double();
	cout << "Enter the weight : "; in >> *weight;
	other.setWeight(*weight);
	delete weight;
	double* price = new double();
	cout << "Enter the price : "; in >> *price;
	other.setPrice(*price);
	delete price;
	double* discount = new double();
	cout << "Enter the discount : "; in >> *discount;
	other.setDiscount(*discount);
	delete discount;
	string* company = new string();
	cout << "Enter the company : "; in >> *company;
	other.setCompany(*company);
	delete company;
	return in;
}
size_t Product::ID = 0;
template<typename T>
class Stack {
	T** products;
	size_t* count;
	double* allWeight;
public:
	static double maxWeight;
	Stack() :products(nullptr), count(nullptr), allWeight(nullptr) {}
	Stack(T**& products, size_t count) {
		setCount(count);
		setProducts(products);
	}
	Stack(Stack<Product>& other) {
		setCount(*other.count);
		setProducts(other.products);
	}
	Stack& operator=(Stack& other) {
		setCount(*other.count);
		setProducts(other.products);
		return *this;
	}
	Stack(Stack&& other) {
		setCount(*other.count);
		setProducts(other.products);
		for (int i = 0; i < *other.count; i++) {
			delete other.products[i];
		}delete[] other.products;
		delete other.count;
	}
	T** getProducts()const {
		return products;
	}
	size_t getCount()const {
		return *count;
	}
	double getAllWeight()const {
		return *allWeight;
	}
	void setCount(size_t count) {
		this->count = new size_t(count);
	}
	void setProducts(T**& products) {
		this->products = new T * [*count];
		for (size_t i = 0; i < *count; i++) {
			this->products[i] = products[i];
		}setAllWeight();
	}
	void setAllWeight() {
		allWeight = new double();
		Product** temp = products;
		for (size_t i = 0; i < *count; i++) {
			*allWeight += temp[i]->getWeight();
		}temp = nullptr;
		assert(*allWeight <= maxWeight && "Error line 241");
	}
	void deleteIndexProduct(int index) {
		Product** temp = new Product * [*count - 1];
		for (int i = 0, j = 0; i < *count; i++) {
			if (i != index) {
				temp[j] = products[i];
				j++;
			}
		}
		delete[]products;
		products = temp;
		temp = nullptr;
		(*count)--;
	}
	void insertByIndexProduct(Product product, int index = (-1)) {
		if (index == (-1))index = (*count);
		throw "Error\n"
		Product** temp = new Product * [*count + 1];
		for (int i = 0, j = 0; j < *count + 1; j++) {
			if (index != j) {
				temp[j] = products[i];
				i++;
			}
			else temp[j] = new Product(product);
		}
		delete[]products;
		products = temp;
		temp = nullptr;
		(*count)++;
	}
	explicit operator T () {
		return *products[0];
	}
	explicit operator size_t() {
		return *count;
	}
	explicit operator double() {
		return *allWeight;
	}
	friend ostream& operator<<(ostream& out, const Stack<Product>& stack);
	friend istream& operator>>(istream& in, Stack<Product>& stack);
	~Stack() {
		if (allWeight != nullptr) {
			delete allWeight;
			allWeight = nullptr;
		}
		if (products != nullptr) {
			for (size_t i = 0; i < *count; i++) {
				delete products[i];
			}delete[]products;
			products = nullptr;
		}
		if (count != nullptr) {
			delete count;
			count != nullptr;
		}
	}
};
ostream& operator<<(ostream& out, const Stack<Product>& stack) {
	cout << "================================================\n";
	out << "Count      : " << stack.getCount() << endl;
	out << "Products   : \n";
	for (size_t i = 0; i < stack.getCount(); i++) {
		out << *stack.products[i] << endl;
	}
	out << "All weight : " << stack.getAllWeight() << endl;
	cout << "================================================\n";
	return out;
}
istream& operator>>(istream& in, Stack<Product>& stack) {
	size_t* count = new size_t();
	cout << "Enter the count : "; in >> *count;
	stack.setCount(*count);
	Product** products = new Product * [*count];
	cout << "Enter the products \n";
	for (size_t i = 0; i < *count; i++) {
		cout << "Enter the prodcut[" << i << "] : " << endl;
		products[i] = new Product();
		in >> *products[i];
	}
	stack.setProducts(products);
	for (size_t i = 0; i < *count; i++) {
		delete products[i];
	}delete[] products;
	delete count;
	return in;
}
double Stack<Product>::maxWeight = 100;
class Wagon {
public:
	string* no;
	double* speed;
	string* country;
	Stack<Product>* stack;
	Wagon* next;
	Wagon* prev;
	Wagon() :no(nullptr), speed(nullptr), country(nullptr), stack(nullptr), next(nullptr), prev(nullptr) {}
	Wagon(const string& no, const double& speed, const string& country, Stack<Product>& stack) :Wagon() {
		this->no = new string(no);
		this->speed = new double(speed);
		this->country = new string(country);
		this->stack = new Stack<Product>();
		*this->stack = stack;
	}
	Wagon(Wagon&& other) {
		this->no = new string(*other.no);
		delete other.no;
		other.no = nullptr;
		this->speed = new double(*other.speed);
		delete other.speed;
		other.speed = nullptr;
		this->country = new string(*other.country);
		delete other.country;
		other.country = nullptr;
		this->stack = new Stack<Product>();
		this->stack = stack;
		delete other.stack;
		other.stack = nullptr;

		this->next = other.next;
		other.next->prev = this;
		other.next = nullptr;

		this->prev = other.prev;
		other.prev->next = this;
		other.prev = nullptr;
	}
	string getWagonByNO()const {
		return *no;
	}
	double getWagonBySpeed()const {
		return *speed;
	}
	string getWagonByCountry()const {
		return*country;
	}
	Stack<Product>& getWagonByStack()const {
		return *stack;
	}
	explicit operator string() {
		return *no;
	}
	explicit operator double() {
		return *speed;
	}
	friend ostream& operator<<(ostream& out, const Wagon& wagon);
	friend istream& operator>>(istream& in, Wagon& wagon);
	~Wagon() {
		if (no != nullptr) {
			delete no;
			no = nullptr;
		}
		if (speed != nullptr) {
			delete speed;
			speed = nullptr;
		}
		if (country != nullptr) {
			delete country;
			country = nullptr;
		}
		if (stack != nullptr) {
			delete stack;
			stack = nullptr;
		}
		if (next != nullptr) {
			next = nullptr;
		}
		if (prev != nullptr) {
			prev = nullptr;
		}
	}
};
ostream& operator<<(ostream& out, const Wagon& wagon) {
	cout << "============================================\n";
	out << "Wagon No      : " << *wagon.no << endl;
	out << "Wagon speed   : " << *wagon.speed << endl;
	out << "Wagon country : " << *wagon.country << endl;
	out << "Wagon stack   : \n" << *wagon.stack << endl;
	out << "Wagon next address : " << wagon.next << endl;
	out << "Wagon previous address : " << wagon.prev << endl;
	cout << "============================================\n";
	return out;
}
istream& operator>>(istream& in, Wagon& wagon) {
	wagon.no = new string();
	cout << "Enter the Wagon No      : "; in >> *wagon.no;
	wagon.speed = new double();
	cout << "Enter the Wagon speed   : "; in >> *wagon.speed;
	wagon.country = new string();
	cout << "Enter the Wagon country : "; in >> *wagon.country;
	wagon.stack = new Stack<Product>();
	cout << "Enter the Wagon Stack   : "; in >> *wagon.stack;
	return in;
}
class Train {
	string* name;
	Wagon* front;
	Wagon* end;
public:
	Train() :name(nullptr), front(NULL), end(NULL) {}
	explicit Train(string name, Wagon*& front, Wagon*& end) {
		setName(name);
		setFront(front);
		setEnd(end);
	}
	string getName()const {
		return *name;
	}
	Wagon* getFront()const {
		return front;
	}
	Wagon* getEnd()const {
		return end;
	}
	void setName(string name) {
		this->name = new string(name);
	}
	void setFront(Wagon* front) {
		this->front = front;
	}
	void setEnd(Wagon* end) {
		this->end = end;
	}
	void deleteAfterWagon(Wagon*& temp) {
		if (temp->prev == NULL && temp->next == NULL);
		else if (temp->prev == NULL) {
			front = temp->next;
			temp->next = NULL;
			front->prev = NULL;
		}
		else if (temp->next == NULL) {
			end = temp->prev;
			temp->prev = NULL;
			end->next = NULL;
		}
		else {
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
		}
		delete temp;
	}
	void addFront(Wagon* add_temp) {
		add_temp->prev = NULL;
		if (front == NULL) {
			end = add_temp;
		}
		else {
			front->prev = add_temp;
			add_temp->next = front;
		}
		front = add_temp;
	}
	void addEnd(Wagon*& add_temp) {
		add_temp->next = NULL;
		if (end == NULL) {
			front = add_temp;
		}
		else {
			end->next = add_temp;
			add_temp->prev = end;
		}
		end = add_temp;
	}
	void addAfterWagon(Wagon* temp, Wagon* add_temp) {
		if (temp->next == NULL) {
			addEnd(add_temp);
		}
		else {
			add_temp->next = temp->next;
			add_temp->prev = temp;
			temp->next->prev = add_temp;
			temp->next = add_temp;
		}
	}
	void forwardTraverse() {
		Wagon* temp = front;
		while (temp != NULL)
		{
			cout << *temp << endl;
			temp = temp->next;
		}
	}
	void backward_traverse() {
		Wagon* temp = end;
		while (temp != NULL)
		{
			cout << *temp << endl;
			temp = temp->prev;
		}
	}
	void updateSpeedByNo(string NO, double speed) {
		Wagon* temp = front;
		while (*temp->no != NO) {
			temp = temp->next;
		}
		*temp->speed = speed;
	}
	void updateCountryByNo(string NO, string country) {
		Wagon* temp = front;
		while (*temp->no != NO) {
			temp = temp->next;
		}
		*temp->country = country;
	}
	void deleteWagonByNo(string NO) {
		Wagon* temp = front;
		while (*temp->no != NO) {
			temp = temp->next;
		}
		deleteAfterWagon(temp);
	}
	void showProductsByNo(string NO) {
		Wagon* temp = front;
		while (*temp->no != NO) {
			temp = temp->next;
		}
		cout << *temp << endl;
	}
	friend ostream& operator<<(ostream& out, const Train& train);
	friend istream& operator>>(istream& in, Train& wagon);
	~Train() {
		if (name != nullptr)
			delete name;
		int* count = new int(0);
		Wagon* temp = front;
		while (temp != NULL) {
			temp = temp->next;
			(*count)++;
		}
		temp = end;
		while (*count > 0) {
			deleteAfterWagon(temp);
			temp = end;
			(*count)--;
		}delete count;
	}
};
ostream& operator<<(ostream& out, const Train& train) {
	cout << "===============================================\n";
	out << "Train name : " << *train.name << endl;
	Wagon* temp = train.front;
	out << "Wagon \n";
	while (temp != NULL) {
		out << *temp << endl;
		temp = temp->next;
	}
	temp = nullptr;
	cout << "===============================================\n";
	return out;
}
istream& operator>>(istream& in, Train& train) {
	string* name = new string();
	cout << "Enter the name : "; in >> *name;
	train.setName(*name);
	delete name;
	int* count = new int();
	cout << "Enter the wagon count : "; in >> *count;
	throw"Error\n";
	Wagon* temp = new Wagon();
	for (int i = 0; i < *count; i++) {
		in >> *temp;
		train.addEnd(temp);
		temp = nullptr;
		temp = new Wagon();
	}
	return in;
}
int main() {}