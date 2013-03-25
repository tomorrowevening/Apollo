//
//  AlphaMask.cpp
//
//  Created by Colin Duffy on 2/27/13.
//
//

#include "AlphaMask.h"

void AlphaMask::setup(int wid, int hei) {
	useMask = true;
	
	string fragSrc = "";
	fragSrc += "uniform sampler2DRect Tex0, Tex1;";
	fragSrc += "void main (void) {";
	fragSrc += "	vec4 image = texture2DRect(Tex0, gl_TexCoord[0].st);";
	fragSrc += "	vec4 composite = texture2DRect(Tex1, gl_TexCoord[1].st);";
	fragSrc += "	gl_FragData[0] = vec4(image.rgb,composite.r);";
	fragSrc += "}";
	
	string vertSrc = "";
	vertSrc += "void main(void) {";
	vertSrc += "	gl_Position = ftransform();";
	vertSrc += "	gl_TexCoord[0] = gl_MultiTexCoord0;";
	vertSrc += "	gl_TexCoord[1] = gl_MultiTexCoord1;";
	vertSrc += "}";
	
	shader.setupShaderFromSource(GL_VERTEX_SHADER, vertSrc);
	shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragSrc);
	
	shader.begin();
	shader.setUniformTexture("Tex0", content, 0);
	shader.setUniformTexture("Tex1", mask, 1);
	shader.end();
}

void AlphaMask::dispose() {
	shader.unload();
}

void AlphaMask::render(float x, float y) {
	if(!useMask) return;
	
	int maskWid = mask.getWidth();
	int maskHei = mask.getHeight();
	
	int contentWid = content.getWidth();
	int contentHei = content.getHeight();
	
	shader.begin();
	glActiveTexture(GL_TEXTURE0_ARB);
	content.bind();
	
	glActiveTexture(GL_TEXTURE1_ARB);
	mask.bind();
	
	glBegin(GL_QUADS);
	
	float offset = 0;
	glMultiTexCoord2d(GL_TEXTURE0_ARB, 0, 0);
	glMultiTexCoord2d(GL_TEXTURE1_ARB, 0, offset);
	glVertex2f(x, y);
	
	glMultiTexCoord2d(GL_TEXTURE0_ARB, contentWid, 0);
	glMultiTexCoord2d(GL_TEXTURE1_ARB, maskWid, offset);
	glVertex2f(x + contentWid, y);
	
	glMultiTexCoord2d(GL_TEXTURE0_ARB, contentWid, contentHei);
	glMultiTexCoord2d(GL_TEXTURE1_ARB, maskWid, maskHei);
	glVertex2f(x + contentWid, y + contentHei);
	
	glMultiTexCoord2d(GL_TEXTURE0_ARB, 0, contentHei);
	glMultiTexCoord2d(GL_TEXTURE1_ARB, 0, maskHei);
	glVertex2f(x, y + contentHei);
	
	glEnd();
	
	glActiveTexture(GL_TEXTURE1_ARB);
	mask.unbind();
	
	glActiveTexture(GL_TEXTURE0_ARB);
	content.unbind();
	
	shader.end();
}
