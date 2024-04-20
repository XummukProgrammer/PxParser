#ifndef _PX_PARSER_MOD_FILE_HEADER_
#define _PX_PARSER_MOD_FILE_HEADER_

#include <PxParser/Document/PxParserNode.hpp>

#include <string>
#include <vector>

namespace PxParser
{
	class ModFile final
	{
	public:
		ModFile() = default;
		~ModFile() = default;

	public:
		void Load(const Node::ChildPtr& node);

	public:
		const std::string& GetName() const;
		const std::vector<std::string>& GetTags() const;
		const std::string& GetPicture() const;
		const std::string& GetVersion() const;
		const std::string& GetSupportedVersion() const;
		const std::string& GetPath() const;
		const std::string& GetRemoteFileId() const;
		const std::vector<std::string>& GetDependencies() const;

	private:
		std::string _name;
		std::vector<std::string> _tags;
		std::string _picture;
		std::string _version;
		std::string _supportedVersion;
		std::string _path;
		std::string _remoteFileId;
		std::vector<std::string> _dependencies;
	};
}

#endif // _PX_PARSER_MOD_FILE_HEADER_
