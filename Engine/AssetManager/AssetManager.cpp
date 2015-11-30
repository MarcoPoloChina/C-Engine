#include "AssetManager.h"
AssetManager::AssetManager(){
	init();
}
void AssetManager::init(){
	loadAssetsDirectory();
	loadSprites(loadSpriteSheets());
}
void AssetManager::loadAssetsDirectory(){
	rapidxml::xml_document<> doc;
	doc.parse<0>(Tools::loadFile("Assets/assets.xml"));
	for(rapidxml::xml_node<>* node = doc.first_node()->first_node();node != NULL;node = node->next_sibling()){
		for(rapidxml::xml_attribute<>* attr = node->first_attribute();attr !=NULL;attr = attr->next_attribute()){
			std::string test_attr = std::string(attr->name(),attr->name_size());
			if(test_attr.compare("type") == 0){
				std::string type(attr->value(),attr->value_size());
				if(type.compare("sprite_sheet") == 0){					
					char* path = node->value();
					std::string default_path = "Assets/";
					char* path_fixed = (char*) malloc(strlen(path)+strlen(default_path.c_str())+1);
					strcpy(path_fixed,default_path.c_str());
					strcat(path_fixed,path);
					_assets[AssetType_SPRITE_SHEET].push_back(path_fixed);
				}else 
				if(type.compare("settings") == 0){
					char* path = node->value();
					std::string default_path = "Assets/";
					char* path_fixed = (char*) malloc(strlen(path)+strlen(default_path.c_str())+1);
					strcpy(path_fixed,default_path.c_str());
					strcat(path_fixed,path);
					_assets[AssetType_SETTINGS].push_back(path_fixed);
				}else
				if(type.compare("sprite_list") == 0){
					char* path = node->value();
					std::string default_path = "Assets/";
					char* path_fixed = (char*) malloc(strlen(path)+strlen(default_path.c_str())+1);
					strcpy(path_fixed,default_path.c_str());
					strcat(path_fixed,path);
					_assets[AssetType_SPRITE_LIST].push_back(path_fixed);
				}
			}else{
				std::cout << "Error wrong asset dictory format attribute" << std::endl;
			}
		}
	}	
}
std::vector<Animation> AssetManager::loadSpriteSheets(){		
	//Loop over all of the sprite sheets
	for(unsigned int i=0;i<_assets[AssetType_SPRITE_SHEET].size();i++){
		//load the xml doc
		rapidxml::xml_document<> doc;
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
					frames.push_back(frame);
				}
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
					std::unordered_map<std::string, int>::const_iterator texture_map_itr = _textureMap.indexes.find(test_string);
					//check if the source texture has been mapped
					if(texture_map_itr == _textureMap.indexes.end()){
						int index = _textureMap.texturesSources.size();
						_textureMap.indexes.insert({test_string,index});
						temp_animation.source = index;
						_textureMap.texturesSources.push_back(test_string);
					}else{
						temp_animation.source = texture_map_itr->second;
					}
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
			std::unordered_map<std::string, int>::const_iterator animation_map_itr = _animationMap.indexes.find(temp_animation.name);
			if(animation_map_itr == _animationMap.indexes.end()){
				int index = _animationMap.animations.size();
				_animationMap.indexes.insert({temp_animation.name,index});
				temp_animation.index = index;
			}
		}
	}
	//Generate a TextureMap based on all of the sprite_sheets sources
	//Loop over all of the 
	
	return _animationMap.animations;
}
std::vector<Sprite> AssetManager::loadSprites(std::vector<Animation> animations){
	for(unsigned int i=0;i<_assets[AssetType_SPRITE_LIST].size();i++){
		rapidxml::xml_document<>  doc;
		doc.parse<0>(Tools::loadFile(_assets[AssetType_SPRITE_LIST][i]));
		for(rapidxml::xml_node<>* node = doc.first_node()->first_node(); node != NULL;node = node->next_sibling()){
			std::unordered_map<std::string, Animation> temp_animations;
			for(rapidxml::xml_node<>* nodei = node->first_node();nodei != NULL;nodei = nodei->next_sibling()){
				std::string test_string(nodei->value(),nodei->value_size());
				std::unordered_map<std::string,Animation>::const_iterator animation_itr = animations.find(test_string);				
				if(animation_itr == animations.end()){
					std::cout << "Error Animation: " << test_string << " not found"	<< std::endl;
				}else{
					temp_animations.insert({test_string,animations.at(test_string)});	
				}
			}
			std::string name;
			int x;
			int y;
			double rotation;
			std::string defaultAnimation;
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
				if(test_attr.compare("defaultAnimation") == 0){	
					defaultAnimation  = std::string(attr->value(),attr->value_size());
				}else{
					std::cout << "Error wrong attribute for animation" << std::endl;	
				}
			}
			Sprite temp_sprite(temp_animations,name,Transform(Vector2d(x,y),rotation),defaultAnimation);
			sprites.insert({temp_sprite.getName(),temp_sprite});
		}
	}
	return sprites;
}