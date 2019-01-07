package com.svlabs.svt.ride;

public class MatricValue {
	private String key;
	private double value;
	public String getKey() {
		return this.key;
	}
	public void setKey(String key) {
		this.key = key;
	}
	public double getValue() {
		return this.value;
	}
	public void setValue(double value) {
		this.value = value;
	}
	@Override
	public String toString() {
		return this.key + " : "+this.value;
	}
	
}
