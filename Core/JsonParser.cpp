﻿//
// JsonParser.cpp
//

#include "JsonParser.h"
#include "LogSystem.h"

bool JsonParser::Parse(const std::string& InPath, Json::Value& OutRoot)
{
	std::ifstream ifs(InPath, std::ifstream::in);

	if (ifs.is_open())
	{
		Json::CharReaderBuilder builder;
		JSONCPP_STRING errs;

		if (!parseFromStream(builder, ifs, &OutRoot, &errs))
		{
			LogSystem::LogError(errs, LogSystem::Category::JsonParser);
			return false;
		}

		return true;
	}
	else
	{
		LogSystem::LogError("Can't open Json file \"" + InPath + "\"", LogSystem::Category::JsonParser);
		return false;
	}
}