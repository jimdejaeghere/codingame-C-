#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Link {
	int node1;
	int node2;
};

int main()
{
	vector<Link> lstLinks;
	vector<int> lstNodes;

	int N; // the total number of nodes in the level, including the gateways
	int L; // the number of links
	int E; // the number of exit gateways
	cin >> N >> L >> E; cin.ignore();
	for (int i = 0; i < L; i++) {
		Link tmp;
		int tmpNode1, tmpNode2;
		cin >> tmpNode1 >> tmpNode2; cin.ignore();
		if (tmpNode1 > tmpNode2)
		{
			tmp.node1 = tmpNode2;
			tmp.node2 = tmpNode1;
		}
		else 
		{
			tmp.node1 = tmpNode1;
			tmp.node2 = tmpNode2;
		}
		lstLinks.push_back(tmp);
	}
	for (int i = 0; i < E; i++) {
		int EI; // the index of a gateway node
		cin >> EI; cin.ignore();
		lstNodes.push_back(EI);
	}

	// game loop
	while (1) {
		vector<int> lstAdjacentNodes;
		int SI; // The index of the node on which the Skynet agent is positioned this turn
		cin >> SI; cin.ignore();
		Link hotLink;
		bool link = false;

		// find all adjacent nodes
		for (int i = 0; i < lstLinks.size(); i++)
		{
			if (lstLinks[i].node1 == SI)
			{
				lstAdjacentNodes.push_back(lstLinks[i].node2);
			}
			else if (lstLinks[i].node2 == SI)
			{
				lstAdjacentNodes.push_back(lstLinks[i].node1);
			}
		}

		// see if adjacentnodes are gateways
		for (int i = 0; i < lstAdjacentNodes.size(); i++)
		{
			for (int j = 0; j < lstNodes.size(); j++)
			{
				if (lstAdjacentNodes[i] == lstNodes[j])
				{
					if (SI > lstNodes[j])
					{
						hotLink.node1 = lstNodes[j];
						hotLink.node2 = SI;
						link = true;
						break;
					}
					else
					{
						hotLink.node1 = SI;
						hotLink.node2 = lstNodes[j];
						link = true;
						break;
					}

				}
			}
		}

		if (link == true)
		{
			for (int i = 0; i < lstLinks.size(); i++)
			{
				if (lstLinks[i].node1 == hotLink.node1 && lstLinks[i].node2 == hotLink.node2)
				{
					lstLinks.erase(lstLinks.begin() + i);
				}
			}
		}
		else
		{
			hotLink.node1 = lstLinks[0].node1;
			hotLink.node2 = lstLinks[0].node2;
			lstLinks.erase(lstLinks.begin());
		}

		cout << hotLink.node1 << " " << hotLink.node2 << endl; // Example: 0 1 are the indices of the nodes you wish to sever the link between
	}
}