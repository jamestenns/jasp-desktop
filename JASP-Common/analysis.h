#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <boost/uuid/uuid.hpp>

#include <map>
#include <list>

#include "options/options.h"

#include "common.h"
#include "version.h"


class Analysis
{
public:

	enum Status { Empty, Initing, Inited, InitedAndWaiting, Running, Complete, Aborting, Aborted, Error };

	Analysis(int id, std::string name, Options *options, Version version, bool isAutorun = true);
	virtual ~Analysis();

	Options *options() const;

	boost::signals2::signal<void (Analysis *source)> optionsChanged;
	boost::signals2::signal<void (Analysis *source)> resultsChanged;

	void setResults(Json::Value results);
	const Json::Value &results() const;
	Json::Value asJSON() const;

	static Status getStatusValue(std::string name);

	const std::string &name() const;
	int id() const;
	bool isAutorun() const;

	virtual void abort();
	void scheduleRun();

	void setOptions(Options* options);

	Status status() const;

	void setStatus(Status status);
	bool visible();
	void setVisible(bool visible);

protected:

	Status _status;
	bool _visible = true;

	Options* _options;

	Json::Value _results;

	int callback(Json::Value results);

private:
	Version _version;
	int _id;
	std::string _name;
	bool _autorun;

	void optionsChangedHandler(Option *option);

};

#endif // ANALYSIS_H
