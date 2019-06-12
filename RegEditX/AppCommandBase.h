#pragma once

struct AppCommandBase abstract {
	AppCommandBase(const CString& name, const CString& desc = L"") : _name(name), _desc(desc) {}
	virtual ~AppCommandBase() = default;

	const CString& GetName() const {
		return _name;
	}

	const CString& GetDesc() const {
		return _desc;
	}

	virtual void Execute() = 0;
	virtual void Undo() = 0;

private:
	CString _name, _desc;
};

struct AppCommandList : AppCommandBase {
	AppCommandList();

	void AddCommand(std::shared_ptr<AppCommandBase> command);

	void Execute() override;
	void Undo() override;

private:
	std::vector<std::shared_ptr<AppCommandBase>> _commands;
};
