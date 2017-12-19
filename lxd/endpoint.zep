namespace Lxd;

class Endpoint
{
    protected config;
    protected curl;
    private endpoint;
    
    /**
     *
     */
    public function __construct(array config, curl, string endpoint = "") -> void
    {
        let this->config   = config;
        let this->curl     = curl;
        let this->endpoint = endpoint;
    }
    
    /**
     *
     */
    public function __get(string method)
    {
        string ns; let ns = this->endpoint."\\".ucfirst(method);

        if class_exists(ns) {
            let this->config["endpoint"] = this->endpoint;
            let this->config["method"] = method;
            return new {ns}(this->config, this->curl);
        }

        if method_exists(this, method) {
            return call_user_func(
                [this, method],
                [this->config, this->curl]
            );
        } else {
            throw new \Exception("Endpoint ".ns.", not implemented.");
        }
    }
    
    /**
     *
     */
    protected function getVersion() -> string
    {
        return (string) this->config["version"];
    }  
    
    /**
     *
     */
    protected function getUrl() -> string
    {
        return (string) this->config["url"];
    }  
    
    /**
     *
     */
    protected function getBase(string endpoint = null) -> string
    {
        return (string) this->getUrl()."/".this->getVersion().(!empty endpoint ? "/".endpoint : null);
    }   
    
    /**
     *
     */
    protected function stripEndpoint(string endpoint = null) -> string
    {
        return (string) str_replace("/".this->getVersion()."/".this->config["endpoint"]."/", null, endpoint);
    } 

}
