l2 randInt(l2 _L,l2 _R) {
  	l2 tmp=0;
 	for(int i=0; i<4; i++)
		tmp=(tmp<<15)^(rand()&((1<<15)-1));
	assert(_L<=_R);
	return _L+tmp%(_R-_L+1);	
}

int main() {
	srand(time(nullptr));
}