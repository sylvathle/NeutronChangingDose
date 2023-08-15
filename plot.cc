void plot()
{
	TFile *f = new TFile("edep.root","read");
	TTree* tree = (TTree*)f->Get("neutron");

	double dist,edep;
	
	tree->SetBranchAddress("dist",&dist);
	tree->SetBranchAddress("fedep",&edep);

	int entries = tree->GetEntries();
	int i=0;

	tree->GetEntry(i);
	std::vector <double> edeps;
	std::vector <double> dists;
	
	auto gr = new TGraph();

	std::vector <double> edepCum;
	std::vector <double> distsCum;
	std::vector <double> NCum;
	for (int j=0;j<10;j++) {edepCum.push_back(0.0);}
	for (int j=0;j<10;j++) {distsCum.push_back(0.0);}
	for (int j=0;j<10;j++) {NCum.push_back(0.0);}

	while (i<entries)
	{
		tree->GetEntry(i);
		int I = (int)-dist/100.0;
		edepCum[I]+=edep;
		distsCum[I]+=dist;
		NCum[I]+=1.0;
		i++;
	
	}

	std::vector <double> edepStd;
	std::vector <double> distsStd;

	for (int j=0;j<10;j++)
	{
		if (NCum[j]==0) {continue;} 
		edepCum[j]=edepCum[j]/NCum[j];
		distsCum[j]=distsCum[j]/NCum[j];
		std::cout << j << " " << edepCum[j] << std::endl;
		gr->AddPoint(distsCum[j],edepCum[j]);
	}

	gr->Draw("AL*");
}
