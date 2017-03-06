# AnnularBuff
AnnularBuff API(环形缓冲区)

该环形缓冲区实现，使用模板，可特化进行相关的操作。
例子如下：
    
  CAnnularBuff<int>  stAnnularBuf(10);
  
	stAnnularBuf.push_back(1);
  
	stAnnularBuf.push_back(2);

	int nElement = stAnnularBuf.pop_front();
  
	std::cout << nElement << endl;
  
	int nElement2 = stAnnularBuf.pop_front();
  
	std::cout << nElement2 << endl;

	int one = stAnnularBuf.getElement(0);
  
	int tow = stAnnularBuf.getElement(1);

	int nLen = stAnnularBuf.getLength();

	std::cout << one << ", " << tow <<", "<<nLen<<endl;
  
  
