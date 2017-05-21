#include "Processor.h"
errors processor(const argument arg, const action act, My_drawing g)
{
	static model mod = init_model();
	errors err = ERROR_NO;

	switch (act) {

	case LOAD:
		err = load_model_prosessor(mod, arg);
		break;

	case CHANGE:
		err = change_points_prosessor(mod, arg);
		break;

	case DRAW:
		err = draw_prosessor(mod, g);
		break;

	case CLEAR:
		err = clear_all_prosessor(mod);
		break;
	default :
		err = ERROR_TASK;
	}
	return err;
}
