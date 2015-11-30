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
	doc.parse<0>(Tools::loadFile("assets.xml"));
	for(rapidxml::xml_node<>* node = doc.first_node()->first_node();node != NULL;node = node->next_sibling()){
		for(rapidxml::xml_attribute<>* attr = node->first_attribute();attr !=NULL;attr = attr->next_attribute()){
			std::string test_attr = std::string(attr->name(),attr->name_size());
			if(test_attr.compare("type") == 0){
				std::string type(attr->value(),attr->value_size());
				if(type.compare("sprite_sheet") == 0){					
					_assets[AssetType_SPRITE_SHEET].push_back(node->value());
				}else 
				if(type.compare("settings") == 0){
					_assets[AssetType_SETTINGS].push_back(node->value());	
				}else
				if(type.compare("sprite_list") == 0){
					_assets[AssetType_SPRITE_LIST].push_back(node->value());	
				}
			}else{
				std::cout << "Error wrong asset dictory format attribute" << std::endl;
			}
		}
	}	
}
std::unordered_map<std::string, Animation> AssetManager::loadSpriteSheets(){
	std::unordered_map<std::string, Animation> animations;
	for(int i=0;i<_assets[AssetType_SPRITE_SHEET].size();i++){
		rapidxml::xml_document<> doc;
		doc.parse<0>(Tools::loadFile(_assets[AssetType_SPRITE_SHEET][i]));
		for(rapidxml::xml_node<>* node = doc.first_node()->first_node();node != NULL;node = node->next_sibling()){
			std::vector<Frame> frames;
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
			Animation temp_animation(frames);								
			for(rapidxml::xml_attribute<>* attr = node->first_attribute(); attr != NULL; attr = attr->next_attribute()){			
				std::string test_attr(attr->name(),attr->name_size());
				if(test_attr.compare("name") == 0){
					temp_animation.name = std::string(attr->value(),attr->value_size());
				}else
				if(test_attr.compare("speed") == 0){
					temp_animation.speed = atoi(attr->value());
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
			animations.insert({temp_animation.name,temp_animation});
		}
	}
	return animations;
}
std::unordered_map<std::string, Sprite> AssetManager::loadSprites(std::unordered_map<std::string, Animation> animations){
	std::unordered_map<std::string, Sprite> sprites;
	for(int i=0;i<_assets[AssetType_SPRITE_LIST].size();i++){
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
			std::cout << "fuck" << std::endl;
		}
	}
	std::cout << sprites.at("test_sprite").getName() << std::endl;
	return sprites;
}
