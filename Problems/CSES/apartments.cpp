#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int nbApplicants, nbPartments, tolerance;
    cin >> nbApplicants >> nbPartments >> tolerance;
    vector<int> applicants(nbApplicants);
    for (int i = 0; i < nbApplicants; i++) cin >> applicants[i];
    sort(applicants.begin(), applicants.end());
    vector<int> partments(nbPartments);
    for (int i = 0; i < nbPartments; i++) cin >> partments[i];
    sort(partments.begin(), partments.end());

    int matches = 0;
    int partmentsCounter = 0;
    for (int i = 0; i < nbApplicants; i++) {
        while (partmentsCounter < nbPartments and partments[partmentsCounter] < applicants[i]-tolerance) partmentsCounter++;
        if (partmentsCounter < nbPartments and applicants[i]-tolerance <= partments[partmentsCounter] and partments[partmentsCounter] <= applicants[i]+tolerance) {
            matches++;
            partmentsCounter++;
        }
    }

    cout << matches;

    int d = 0;
    d++;
}