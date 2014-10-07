/*
 * =====================================================================================
 *
 *       Filename:  deErr.C
 *
 *    Description:  debug histo Error
 *
 *        Version:  1.0
 *        Created:  09/21/2014 11:34:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


{
	int n = 2;
	int np = 0;
	int j = 7;
	int i = 6;
	double de_sum = 0;
	for ( int fn = 0; fn < s3; fn++ ) {
		de_sum += dVp[fn][n][np][j][i]*dVp[fn][n][np][j][i];
		cout << " fn = " << fn << "\tdVp = " << dVp[fn][n][np][j][i] << "\t dVp - dVp_mean = " << dVp[fn][n][np][j][i] - dVp[s3][n][np][j][i] << endl;
	}
	cout << "de_sum/s3 = " << de_sum/s3 << "\t dVp_mean^2 = " << dVp[s3][n][np][j][i]*dVp[s3][n][np][j][i] << endl;
}
