#include "SceneSelection.h"

SceneSelection::SceneSelection() {
	SceneNo = 1;
}

SceneSelection::~SceneSelection() {
}

SceneSelection* SceneSelection::GetInstance() {

	static SceneSelection SceneSelection;

	return &SceneSelection;

}