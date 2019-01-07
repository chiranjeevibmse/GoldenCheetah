package com.svlabs.svt.matrics;

import java.util.List;

import com.svlabs.svt.ride.MatricValue;
import com.svlabs.svt.ride.RideFilePoint;
import com.svlabs.svt.ride.SaarRideFileReader;

public class TestMatricsGen {
	public static void main(String[] args) {
		SaarRideFileReader reader = new SaarRideFileReader();
		RideFilePoint[] rideFilePoints = reader.readFile("/Users/chiranjeevi/MyData/fit/Fit files from Subbu/RunningFIT.fit");
		
		SaarMatricsGenerator gen = new SaarMatricsGenerator();
		gen.addMatrics("ninety_five_percent_hr");
		gen.addMatrics("average_hr");
		for(RideFilePoint eachPoint : rideFilePoints) {
			System.out.println(eachPoint);
			gen.addRidePoint(eachPoint);
		}
		gen.analyseMatric();
		List<MatricValue> matricValues = SaarMatricsGenerator.getMatricValues();
		for(MatricValue eachMat : matricValues) {
			System.out.println(eachMat);
		}
	}
}
