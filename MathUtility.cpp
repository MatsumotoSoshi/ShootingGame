#include "MathUtility.h"
#include <cmath>
using namespace KamataEngine;

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result.m[i][j] = m1.m[i][0] * m2.m[0][j] + m1.m[i][1] * m2.m[1][j] + m1.m[i][2] * m2.m[2][j] + m1.m[i][3] * m2.m[3][j];
		}
	}

	return result;
}

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 scaleMatrix = {scale.x, 0.0f, 0.0f, 0.0f, 0.0f, scale.y, 0.0f, 0.0f, 0.0f, 0.0f, scale.z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

	Matrix4x4 rotateXMatrix = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, cos(rotate.x), sin(rotate.x), 0.0f, 0.0f, -sin(rotate.x), cos(rotate.x), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

	Matrix4x4 rotateYMatrix = {cos(rotate.y), 0.0f, -sin(rotate.y), 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, sin(rotate.y), 0.0f, cos(rotate.y), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

	Matrix4x4 rotateZMatrix = {cos(rotate.z), sin(rotate.z), 0.0f, 0.0f, -sin(rotate.z), cos(rotate.z), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

	Matrix4x4 translateMatrix = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, translate.x, translate.y, translate.z, 1.0f};

	Matrix4x4 rotateMatrix = Multiply(Multiply(rotateXMatrix, rotateYMatrix), rotateZMatrix);

	Matrix4x4 worldMatrix = Multiply(Multiply(scaleMatrix, rotateMatrix), translateMatrix);

	return worldMatrix;
}
