class CfgPatches
{
	class cs_code_module //Change this
	{ 
		name = "cs code stuff"; //Change this
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.82;
		requiredAddons[] = { "rvcss_plugin" };
		author = "Killerswin2"; //Change this
		authors[] = { "Killerswin2" }; //Change this
		version = "1.0";
		versionStr = "1.0";
		versionAr[] = { 1,0 };
	};
};

class rvcss
{
	class test_cs_code //Change this. It's the classname that you pass to csLoad
	{ 
		assemblyName = "arma_code";
		assemblyClassName = "Printer";
	};
};