#include "AssetManager.h"
AssetManager::AssetManager(){
	init();
}
void AssetManager::init(){ //loads all of the assets
	loadAssetsDirectory();
	loadSpriteSheets();
	loadSprites();
	loadPrefabs();
	loadScenePrefabs();
}
void AssetManager::loadAssetsDirectory(){
	//parse the assets.xml
	rapidxml::xml_document<> doc;
	doc.parse<0>(Tools::loadFile("../Assets/assets.xml"));
	//loop over each asset path
	for(rapidxml::xml_node<>* node = doc.first_node()->first_node();node != NULL;node = node->next_sibling()){
		//loop over each path's attributes
		for(rapidxml::xml_attribute<>* attr = node->first_attribute();attr !=NULL;attr = attr->next_attribute()){
			//determine the type of the path and then push the path to the apportivate vector 
			std::string test_attr = std::string(attr->name(),attr->name_size());
			if(test_attr.compare("type") == 0){
				std::string type(attr->value(),attr->value_size());
				if(type.compare("sprite_sheet") == 0){					
					char* path = node->value();
					std::string default_path = "../Assets/";
					char* path_fixed = (char*) malloc(strlen(path)+strlen(default_path.c_str())+1);
					strcpy(path_fixed,default_path.c_str());
					strcat(path_fixed,path);
					_assets[AssetType_SPRITE_SHEET].push_back(path_fixed);
				}else 
				if(type.compare("settings") == 0){
					char* path = node->value();
					std::string default_path = "../Assets/";
					char* path_fixed = (char*) malloc(strlen(path)+strlen(default_path.c_str())+1);
					strcpy(path_fixed,default_path.c_str());
					strcat(path_fixed,path);
					_assets[AssetType_SETTINGS].push_back(path_fixed);
				}else
				if(type.compare("sprite_list") == 0){
					char* path = node->value();
					std::string default_path = "../Assets/";
					char* path_fixed = (char*) malloc(strlen(path)+strlen(default_path.c_str())+1);
					strcpy(path_fixed,default_path.c_str());
					strcat(path_fixed,path);
					_assets[AssetType_SPRITE_LIST].push_back(path_fixed);
				}else
				if(type.compare("prefab_list") == 0){
					char* path = node->value();
					std::string default_path = "../Assets/";
					char* path_fixed = (char*) malloc(strlen(path)+strlen(default_path.c_str())+1);
					strcpy(path_fixed,default_path.c_str());
					strcat(path_fixed,path);
					_assets[AssetType_PREFAB_LIST].push_back(path_fixed);
				}else
				if(type.compare("scene_prefab_list") == 0){
					char* path = node->value();
					std::string default_path = "../Assets/";
					char* path_fixed = (char*) malloc(strlen(path)+strlen(default_path.c_str())+1);
					strcpy(path_fixed,default_path.c_str());
					strcat(path_fixed,path);
					_assets[AssetType_SCENE_PREFAB_LIST].push_back(path_fixed);
				}
			}else{
				std::cout << "Error wrong asset dictory format attribute" << std::endl;
			}
		}
	}	
}
/**
 * @brief Loads the sprits sheets into the _animationsMap
 */
void AssetManager::loadSpriteSheets(){		
	//Loop over all of the sprite sheets
	for(unsigned int i=0;i<_assets[AssetType_SPRITE_SHEET].size();i++){
		//load the xml doc
		rapidxml::xml_document<> doc;
		Tools::PrintDebug(_assets[AssetType_SPRITE_SHEET][i]);
		doc.parse<0>(Tools::loadFile(_assets[AssetType_SPRITE_SHEET][i]));
		//loop of all of the Animation Nodes
		for(rapidxml::xml_node<>* node = doc.first_node()->first_node();node != NULL;node = node->next_sibling()){
		std::vector<Frame> frames;
			//For each animation node loop of all of the frame nodes populating a vector of frames
			for(rapidxml::xml_node<>* nodei = node->first_node();nodei != NULL;nodei = nodei->next_sibling()){
				Frame frame;
				for(rapidxml::xml_attribute<>* attr = nodei->first_attribute();attr != NULL; attr = attr->next_attribute()){
					std::string test_attr(attr->name(), attr->name_size());
					int value = atoi(attr->value());
					if(test_attr.compare("x") == 0){
						frame.x = value;	
					}else
					if(test_attr.compare("y") == 0){
						frame.y = value;					
					}else
					if(test_attr.compare("width") == 0){
						frame.width = value;	
					}else
					if(test_attr.compare("height") == 0){
						frame.height = value;	
					}else{
						std::cout << "Error wrong attribut for frame" << std::endl;	
					}
				}
				frames.push_back(frame);
			}
			//make a temp animation from those frames
			Animation temp_animation(frames);								
			//loop of all of the attributes for the animation node
			for(rapidxml::xml_attribute<>* attr = node->first_attribute(); attr != NULL; attr = attr->next_attribute()){			
				std::string test_attr(attr->name(),attr->name_size());
				if(test_attr.compare("name") == 0){
					temp_animation.name = std::string(attr->value(),attr->value_size());
				}else
				if(test_attr.compare("speed") == 0){
					temp_animation.speed = atoi(attr->value());
				}else
				if(test_attr.compare("source") == 0){
					std::string test_string = std::string(attr->value(),attr->value_size());
					_textureMap.addObject(test_string,test_string);
				}else
				if(test_attr.compare("repeating") == 0){
					std::string temp_value(attr->value(),attr->value_size());
					if(temp_value.compare("true")){
						temp_animation.repeating = true;	
					}
				}else{
					std::cout << "Error wrong attribut for animation" << std::endl;	
				}
			}
			//check if the animation has been mapped
			_animationMap.addObject(temp_animation.name,temp_animation);
		}
	}
	//Generate a TextureMap based on all of the sprite_sheets sources
	//Loop over all of the 
	
}
/**
 * @brief loads the sprites from the sprite lists using the _animationsMap to populate the _spritesMap
 */
void AssetManager::loadSprites(){
	for(unsigned int i=0;i<_assets[AssetType_SPRITE_LIST].size();i++){
		rapidxml::xml_document<>  doc;
		doc.parse<0>(Tools::loadFile(_assets[AssetType_SPRITE_LIST][i]));
		for(rapidxml::xml_node<>* node = doc.first_node()->first_node(); node != NULL;node = node->next_sibling()){
			std::vector<Animation> temp_animations;
			for(rapidxml::xml_node<>* nodei = node->first_node();nodei != NULL;nodei = nodei->next_sibling()){
				std::string test_string(nodei->value(),nodei->value_size());
				int test_index = _animationMap.checkObject(test_string);
				if(test_index == -1){
					std::cout << "Error Animation: " << test_string << " not found"	<< std::endl;
				}else{
					temp_animations.push_back(_animationMap.getObject(test_index));	
				}
			}
			std::string name;
			int x;
			int y;
			double rotation;
			int defaultAnimation;
			int layer;
			for(rapidxml::xml_attribute<>* attr = node->first_attribute();attr != NULL;attr = attr->next_attribute()){
				std::string test_attr(attr->name(),attr->name_size());
				if(test_attr.compare("name") == 0){	
					name = std::string(attr->value(),attr->value_size());
				}else
				if(test_attr.compare("x") == 0){	
					x = atoi(attr->value());
				}else
				if(test_attr.compare("y") == 0){	
					y = atoi(attr->value());
				}else
				if(test_attr.compare("rotation") == 0){	
					rotation  = atof(attr->value());
				}else
				if(test_attr.compare("layer") == 0){	
					layer = atoi(attr->value());
				}else
				if(test_attr.compare("defaultAnimation") == 0){	
					defaultAnimation  = atoi(attr->value());
				}else{
					std::cout << "Error wrong attribute for animation" << std::endl;	
				}
			}
			Sprite temp_sprite(temp_animations,name,Transform(Vector2d(x,y),rotation),defaultAnimation,layer);
			_spriteMap.addObject(name,temp_sprite);
		}
	}
}
void AssetManager::loadPrefabs(){
	for(unsigned int i=0;i<_assets[AssetType_PREFAB_LIST].size();i++){
		rapidxml::xml_document<> doc;
		Tools::PrintDebug(_assets[AssetType_PREFAB_LIST][i]);
		doc.parse<0>(Tools::loadFile(_assets[AssetType_PREFAB_LIST][i]));
		for(rapidxml::xml_node<>* node = doc.first_node()->first_node(); node != NULL; node = node->next_sibling()){
			std::vector<ComponentPrefab> temp_components;
			for(rapidxml::xml_node<>* nodei = node->first_node();nodei != NULL; nodei = nodei->next_sibling()){
				for(rapidxml::xml_attribute<>* attr = nodei->first_attribute();attr != NULL;attr = attr->next_attribute()){
					std::string test_attr(attr->name(),attr->name_size());	
					if(test_attr.compare("type") == 0){	
						 std::string test_type(attr->value(),attr->value_size());
						 if(test_type.compare("sprite") == 0){
							temp_components.push_back(ComponentPrefab(ComponentType::Sprite,std::string(nodei->value(),nodei->value_size())));
						 }else
						 if(test_type.compare("logic") == 0){
							temp_components.push_back(ComponentPrefab(ComponentType::Logic,std::string(nodei->value(),nodei->value_size())));
						 }else{
							std::cout << "Error not component type" << std::endl; 
						 }
					}else{
						std::cout << "Error component type not found" << std::endl;
					}
				}	
			}
			std::string prefab_name;
			for(rapidxml::xml_attribute<>* attr = node->first_attribute();attr != NULL;attr=attr->next_attribute()){
				std::string test_attr(attr->name(),attr->name_size());
				if(test_attr.compare("name") == 0){	
					prefab_name = std::string(attr->value(),attr->value_size());
				}else{
					std::cout << "Error unknown attribute" << std::endl;	
				}
			}
			std::cout << prefab_name << std::endl;
			Prefab temp_prefab(prefab_name,temp_components);
			_prefabs.addObject(prefab_name,temp_prefab);
		}
	}
}
void AssetManager::loadScenePrefabs(){
	for(unsigned int i=0;i<_assets[AssetType_SCENE_PREFAB_LIST].size();i++){
		rapidxml::xml_document<> doc;
		doc.parse<0>(Tools::loadFile(_assets[AssetType_SCENE_PREFAB_LIST][i]));
		for(rapidxml::xml_node<>* node = doc.first_node()->first_node(); node != NULL; node = node->next_sibling()){
			std::vector<std::string> temp_prefabs;
			for(rapidxml::xml_node<>* nodei = node->first_node()->first_node();nodei != NULL; nodei = nodei->next_sibling()){
				std::string prefab_name(nodei->value(),nodei->value_size());
				if(_prefabs.checkObject(prefab_name) == -1){
					std::cout << "Error Prefab not found" << std::endl;
				}else{
					temp_prefabs.push_back(prefab_name);
				}
			}
			std::string scene_name;
			for(rapidxml::xml_attribute<>* attr = node->first_attribute();attr != NULL;attr=attr->next_attribute()){
				std::string test_attr(attr->name(),attr->name_size());
				if(test_attr.compare("name") == 0){	
					scene_name = std::string(attr->value(),attr->value_size());
				}else{
					std::cout << "Error unknown attribute" << std::endl;	
				}
			}
			std::cout << scene_name << std::endl;
			ScenePrefab temp_scene(scene_name,temp_prefabs);
			_scenePrefabs.addObject(scene_name,temp_scene);
		}
	}
}
void AssetManager::addLogic(Logic* logic){
	_logicPointers.addObject(logic->getName(),logic);
}
