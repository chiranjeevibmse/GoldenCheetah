package com.svlabs.svt.matrics;

import java.util.ArrayList;
import java.util.List;

import com.svlabs.svt.ride.MatricValue;
import com.svlabs.svt.ride.RideFilePoint;

public class SaarMatricsGenerator {
	private static List<RideFilePoint> ridePoints;
	private static List<String> matricsToCalculate;
	
	private static List<MatricValue> matricValues;
	public void addMatricValue(MatricValue matricValue) {
		matricValues.add(matricValue);
	}
	public static List<MatricValue> getMatricValues() {
		return matricValues;
	}
	public void addMatrics(String matric) {
		SaarMatricsGenerator.matricsToCalculate.add(matric);
	}
	public String[] getAllMatrics() {
		String[] s = new String[matricsToCalculate.size()];
		return SaarMatricsGenerator.matricsToCalculate.toArray(s);
	}
	public RideFilePoint[] getRidePoints() {
		RideFilePoint[] rides = new RideFilePoint[ridePoints.size()];
		return SaarMatricsGenerator.ridePoints.toArray(rides);
	}
	public void addRidePoint(RideFilePoint point) {
		SaarMatricsGenerator.ridePoints.add(point);
	}
	public native void analyseMatric();
	static {
		System.loadLibrary("GoldenCheetah");
		SaarMatricsGenerator.ridePoints = new ArrayList<>();
		SaarMatricsGenerator.matricsToCalculate = new ArrayList<>();
		SaarMatricsGenerator.matricValues = new ArrayList<>();
	}
}
