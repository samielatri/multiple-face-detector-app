#ifndef _MODEL_H_
#define _MODEL_H_

#ifdef __unix__         
  #define FACE_DEFINITION "Resources/model/haarcascade_frontalface_default.xml"
	#define OUTPUT_FILE "output/output.jpg"
#elif defined(_WIN32) || defined(WIN32) 
	#define FACE_DEFINITION "Resources\\model\\haarcascade_frontalface_default.xml"
	#define OUTPUT_FILE "output\\output.jpg"
#endif /* __unix__ */

#endif  /* _MODEL_H_ */
