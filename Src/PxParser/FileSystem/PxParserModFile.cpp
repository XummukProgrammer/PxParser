#include "PxParserModFile.hpp"

namespace PxParser
{
	void ModFile::Load(const Node::ChildPtr& node)
	{
		_name = node->GetOrCreateValue("name")->GetValue();
		_picture = node->GetOrCreateValue("picture")->GetValue();
		_version = node->GetOrCreateValue("version")->GetValue();
		_supportedVersion = node->GetOrCreateValue("supported_version")->GetValue();
		_path = node->GetOrCreateValue("path")->GetValue();
		_remoteFileId = node->GetOrCreateValue("remote_file_id")->GetValue();

		const auto& tags = node->GetOrCreateChild("tags")->GetValue("Array");
		for (const auto& tag : tags)
		{
			_tags.push_back(tag->GetValue());
		}
	}

	const std::string& ModFile::GetName() const
	{
		return _name;
	}

	const std::vector<std::string>& ModFile::GetTags() const
	{
		return _tags;
	}

	const std::string& ModFile::GetPicture() const
	{
		return _picture;
	}

	const std::string& ModFile::GetVersion() const
	{
		return _version;
	}

	const std::string& ModFile::GetSupportedVersion() const
	{
		return _supportedVersion;
	}

	const std::string& ModFile::GetPath() const
	{
		return _path;
	}

	const std::string& ModFile::GetRemoteFileId() const
	{
		return _remoteFileId;
	}
}
